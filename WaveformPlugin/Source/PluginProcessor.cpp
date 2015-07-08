/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
WaveformPluginAudioProcessor::WaveformPluginAudioProcessor()
{
}

WaveformPluginAudioProcessor::~WaveformPluginAudioProcessor()
{
}

//==============================================================================
const String WaveformPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int WaveformPluginAudioProcessor::getNumParameters()
{
    return 0;
}

float WaveformPluginAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void WaveformPluginAudioProcessor::setParameter (int index, float newValue)
{
}

const String WaveformPluginAudioProcessor::getParameterName (int index)
{
    return String();
}

const String WaveformPluginAudioProcessor::getParameterText (int index)
{
    return String();
}

const String WaveformPluginAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String WaveformPluginAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool WaveformPluginAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool WaveformPluginAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool WaveformPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WaveformPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WaveformPluginAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double WaveformPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WaveformPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WaveformPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WaveformPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String WaveformPluginAudioProcessor::getProgramName (int index)
{
    return String();
}

void WaveformPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WaveformPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void WaveformPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    sendChangeMessage();
}

void WaveformPluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    const int numSamples = buffer.getNumSamples();
    
    for (int i = 0; i < numSamples; ++i)
    {
        float inputSample = 0;
        
        for (int chan = 0; chan < getNumInputChannels(); ++chan)
            if (buffer.getReadPointer(chan) != nullptr)
                inputSample += std::abs (buffer.getReadPointer(chan)[i]);  // find the sum of all the channels
        
        // NOTICE: THIS IS NOT CONCURRENCY SAFE BY ANY WAY
        // we assume we have only single consumer/producer
        if (shouldPassToUI){
            lastKnownBufferSize = numSamples;
            waveformBuffer.push(10.0f * inputSample); // boost the level to make it more easily visible.
        }
    }
    sendChangeMessage();
}

//==============================================================================
bool WaveformPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WaveformPluginAudioProcessor::createEditor()
{
    return new WaveformPluginAudioProcessorEditor (*this);
}

//==============================================================================
void WaveformPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WaveformPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WaveformPluginAudioProcessor();
}
