/*
 ==============================================================================
 
 WaveformComponent.h
 Created: 30 Jun 2015 1:36:02pm
 Author:  Tal Aviram
 
 ==============================================================================
 */

#ifndef WAVEFORMCOMPONENT_H_INCLUDED
#define WAVEFORMCOMPONENT_H_INCLUDED

//==============================================================================
/* This component scrolls a continuous waveform showing the audio that's
 coming into whatever audio inputs this object is connected to.
 */
class WaveformComponent  : public Component,
                           private Timer
{
public:
    WaveformComponent()
    : nextSample (0), subSample (0), accumulator (0)
    {
        setOpaque (true);
        clear();
        
        startTimerHz (75); // use a timer to keep repainting this component
    }
    
    void clearWaveformBuffer()
    {
        clear();
    }
    
    void onWaveformUpdate(std::queue<float>& waveformBuffer, int lastKnownBufferSize){
        for (int i=0; i<lastKnownBufferSize;i++){
            if (!waveformBuffer.empty()){
                pushSample(waveformBuffer.front());
                waveformBuffer.pop();
            }
        }
    }
    
    bool skipFrames = true;     // makes simple "interlaced" look by skipping sample frames..
    
private:
    float samples[1024];
    int nextSample, subSample;
    float accumulator;
    
    WaveformPluginAudioProcessor* processor;
    
    
    void clear()
    {
        zeromem (samples, sizeof (samples));
        accumulator = 0;
        subSample = 0;
    }
    
    void paint (Graphics& g) override
    {
        g.fillAll(Colours::grey.withAlpha(0.3f));
        
        const float midY = getHeight() * 0.5f;
        int samplesAgo = (nextSample + numElementsInArray (samples) - 1);
        
        RectangleList<float> waveform;
        waveform.ensureStorageAllocated ((int) numElementsInArray (samples));
        
        float sumSamples = 0;
        
        for (int x = jmin (getWidth(), (int) numElementsInArray (samples)); --x >= 0;)
        {
            sumSamples += samples[x];
            
            bool interlacedLook;
            
            if (skipFrames){
                interlacedLook = fmod(x,2)!=0;
            }
            else{
                interlacedLook = false;
            }
            
            if (interlacedLook){
                const float sampleSize = midY * samples [samplesAgo-- % numElementsInArray (samples)];
                waveform.addWithoutMerging (Rectangle<float> ((float) x, midY - sampleSize, 1.0f, sampleSize * 2.0f));
            }
        }
        
        g.setColour (Colours::whitesmoke);
        g.fillRectList (waveform);
        g.setFont (15.0f);
        
        float avgValue = sumSamples/numElementsInArray(samples);
        
        g.drawText (String::formatted("AvgBufVal: %f",avgValue), getLocalBounds(), Justification::bottomLeft, 1);
    }
    
    void timerCallback() override
    {
        repaint();
    }
    
    void pushSample (const float newSample)
    {
        accumulator += newSample;
        
        if (subSample == 0)
        {
            const int inputSamplesPerPixel = 200;
            
            samples[nextSample] = accumulator / inputSamplesPerPixel;
            nextSample = (nextSample + 1) % numElementsInArray (samples);
            subSample = inputSamplesPerPixel;
            accumulator = 0;
        }
        else
        {
            --subSample;
        }
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformComponent);
};

#endif  // WAVEFORMCOMPONENT_H_INCLUDED
