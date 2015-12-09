/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.0.2

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_2A11819DD3996C18__
#define __JUCE_HEADER_2A11819DD3996C18__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    !!THIS IS AUTO GENERATED!! It's not actually in use.
    I've just used it for quick gui drawing/sketching and copy from it.
                                                                    //[/Comments]
*/
class SimpleUI  : public Component,
                  public SliderListener,
                  public ButtonListener
{
public:
    //==============================================================================
    SimpleUI ();
    ~SimpleUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> clipSlider;
    ScopedPointer<Label> clipLabel;
    ScopedPointer<Slider> bitsSlider;
    ScopedPointer<Label> bitsLabel;
    ScopedPointer<Slider> samplerateSlider;
    ScopedPointer<Label> samplerateLabel;
    ScopedPointer<Slider> levelSlider;
    ScopedPointer<Label> levelLabel;
    ScopedPointer<Slider> nonlinSlider;
    ScopedPointer<Label> nonlinLabel;
    ScopedPointer<Slider> postfiltSlider;
    ScopedPointer<Label> postfiltLabel;
    ScopedPointer<TextButton> nonlinmodeButton;
    ScopedPointer<TextButton> postfiltmodeButton;
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<TextButton> undoBtn;
    ScopedPointer<TextButton> redoBtn;
    ScopedPointer<Label> label;
    ScopedPointer<Label> actionText;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2A11819DD3996C18__
