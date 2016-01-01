/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SimpleUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SimpleUI::SimpleUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    // WARNING!!!! WE DO NOT USE THIS COMPONENT AT ALL! READ HEADER!
    //[/Constructor_pre]

    addAndMakeVisible (clipSlider = new Slider ("new slider"));
    clipSlider->setRange (0, 10, 0);
    clipSlider->setSliderStyle (Slider::Rotary);
    clipSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    clipSlider->addListener (this);

    addAndMakeVisible (clipLabel = new Label ("clipLabel",
                                              TRANS("clip")));
    clipLabel->setFont (Font (15.00f, Font::plain));
    clipLabel->setJustificationType (Justification::centred);
    clipLabel->setEditable (false, false, false);
    clipLabel->setColour (TextEditor::textColourId, Colours::black);
    clipLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bitsSlider = new Slider ("bitsSlider"));
    bitsSlider->setRange (0, 10, 0);
    bitsSlider->setSliderStyle (Slider::Rotary);
    bitsSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    bitsSlider->addListener (this);

    addAndMakeVisible (bitsLabel = new Label ("bitsLabel",
                                              TRANS("bits")));
    bitsLabel->setFont (Font (15.00f, Font::plain));
    bitsLabel->setJustificationType (Justification::centred);
    bitsLabel->setEditable (false, false, false);
    bitsLabel->setColour (TextEditor::textColourId, Colours::black);
    bitsLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (samplerateSlider = new Slider ("samplerateSlider"));
    samplerateSlider->setRange (0, 10, 0);
    samplerateSlider->setSliderStyle (Slider::Rotary);
    samplerateSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    samplerateSlider->addListener (this);

    addAndMakeVisible (samplerateLabel = new Label ("samplerateLabel",
                                                    TRANS("samplerate")));
    samplerateLabel->setFont (Font (15.00f, Font::plain));
    samplerateLabel->setJustificationType (Justification::centred);
    samplerateLabel->setEditable (false, false, false);
    samplerateLabel->setColour (TextEditor::textColourId, Colours::black);
    samplerateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (levelSlider = new Slider ("levelSlider"));
    levelSlider->setRange (0, 10, 0);
    levelSlider->setSliderStyle (Slider::Rotary);
    levelSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    levelSlider->addListener (this);

    addAndMakeVisible (levelLabel = new Label ("levelLabel",
                                               TRANS("level")));
    levelLabel->setFont (Font (15.00f, Font::plain));
    levelLabel->setJustificationType (Justification::centred);
    levelLabel->setEditable (false, false, false);
    levelLabel->setColour (TextEditor::textColourId, Colours::black);
    levelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (nonlinSlider = new Slider ("nonlinSlider"));
    nonlinSlider->setRange (0, 10, 0);
    nonlinSlider->setSliderStyle (Slider::Rotary);
    nonlinSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    nonlinSlider->addListener (this);

    addAndMakeVisible (nonlinLabel = new Label ("nonlinLabel",
                                                TRANS("nonlin")));
    nonlinLabel->setFont (Font (15.00f, Font::plain));
    nonlinLabel->setJustificationType (Justification::centred);
    nonlinLabel->setEditable (false, false, false);
    nonlinLabel->setColour (TextEditor::textColourId, Colours::black);
    nonlinLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (postfiltSlider = new Slider ("postfiltSlider"));
    postfiltSlider->setRange (0, 10, 0);
    postfiltSlider->setSliderStyle (Slider::Rotary);
    postfiltSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    postfiltSlider->addListener (this);

    addAndMakeVisible (postfiltLabel = new Label ("postfiltLabel",
                                                  TRANS("postfilt")));
    postfiltLabel->setFont (Font (15.00f, Font::plain));
    postfiltLabel->setJustificationType (Justification::centred);
    postfiltLabel->setEditable (false, false, false);
    postfiltLabel->setColour (TextEditor::textColourId, Colours::black);
    postfiltLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (nonlinmodeButton = new TextButton ("nonlinmodeButton"));
    nonlinmodeButton->setButtonText (TRANS("S<>S&H"));
    nonlinmodeButton->addListener (this);

    addAndMakeVisible (postfiltmodeButton = new TextButton ("postfiltmodeButton"));
    postfiltmodeButton->setButtonText (TRANS("Even/Odd"));
    postfiltmodeButton->addListener (this);

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("Preset Manager")));
    groupComponent->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (undoBtn = new TextButton ("undoBtn"));
    undoBtn->setButtonText (TRANS("undo"));
    undoBtn->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    undoBtn->addListener (this);
    undoBtn->setColour (TextButton::buttonColourId, Colours::red);

    addAndMakeVisible (redoBtn = new TextButton ("redoBtn"));
    redoBtn->setButtonText (TRANS("redo"));
    redoBtn->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    redoBtn->addListener (this);
    redoBtn->setColour (TextButton::buttonColourId, Colours::chartreuse);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Last Action:")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (actionText = new Label ("actionText",
                                               TRANS("label text")));
    actionText->setFont (Font (15.00f, Font::plain));
    actionText->setJustificationType (Justification::centredLeft);
    actionText->setEditable (false, false, false);
    actionText->setColour (TextEditor::textColourId, Colours::black);
    actionText->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (410, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SimpleUI::~SimpleUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    clipSlider = nullptr;
    clipLabel = nullptr;
    bitsSlider = nullptr;
    bitsLabel = nullptr;
    samplerateSlider = nullptr;
    samplerateLabel = nullptr;
    levelSlider = nullptr;
    levelLabel = nullptr;
    nonlinSlider = nullptr;
    nonlinLabel = nullptr;
    postfiltSlider = nullptr;
    postfiltLabel = nullptr;
    nonlinmodeButton = nullptr;
    postfiltmodeButton = nullptr;
    groupComponent = nullptr;
    undoBtn = nullptr;
    redoBtn = nullptr;
    label = nullptr;
    actionText = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SimpleUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::blueviolet);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SimpleUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    clipSlider->setBounds (0, 0, 100, 100);
    clipLabel->setBounds (0, 101, 100, 24);
    bitsSlider->setBounds (101, 0, 100, 100);
    bitsLabel->setBounds (101, 101, 100, 24);
    samplerateSlider->setBounds (201, 0, 100, 100);
    samplerateLabel->setBounds (201, 101, 100, 24);
    levelSlider->setBounds (301, 0, 100, 100);
    levelLabel->setBounds (301, 101, 100, 24);
    nonlinSlider->setBounds (0, 125, 100, 100);
    nonlinLabel->setBounds (0, 225, 100, 24);
    postfiltSlider->setBounds (201, 125, 100, 100);
    postfiltLabel->setBounds (201, 225, 100, 24);
    nonlinmodeButton->setBounds (101, 125, 100, 100);
    postfiltmodeButton->setBounds (301, 125, 100, 100);
    groupComponent->setBounds (0, 250, 410, 64);
    undoBtn->setBounds (16, 272, 40, 24);
    redoBtn->setBounds (56, 272, 40, 24);
    label->setBounds (104, 272, 104, 24);
    actionText->setBounds (192, 272, 208, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SimpleUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == clipSlider)
    {
        //[UserSliderCode_clipSlider] -- add your slider handling code here..
        //[/UserSliderCode_clipSlider]
    }
    else if (sliderThatWasMoved == bitsSlider)
    {
        //[UserSliderCode_bitsSlider] -- add your slider handling code here..
        //[/UserSliderCode_bitsSlider]
    }
    else if (sliderThatWasMoved == samplerateSlider)
    {
        //[UserSliderCode_samplerateSlider] -- add your slider handling code here..
        //[/UserSliderCode_samplerateSlider]
    }
    else if (sliderThatWasMoved == levelSlider)
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider]
    }
    else if (sliderThatWasMoved == nonlinSlider)
    {
        //[UserSliderCode_nonlinSlider] -- add your slider handling code here..
        //[/UserSliderCode_nonlinSlider]
    }
    else if (sliderThatWasMoved == postfiltSlider)
    {
        //[UserSliderCode_postfiltSlider] -- add your slider handling code here..
        //[/UserSliderCode_postfiltSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SimpleUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == nonlinmodeButton)
    {
        //[UserButtonCode_nonlinmodeButton] -- add your button handler code here..
        //[/UserButtonCode_nonlinmodeButton]
    }
    else if (buttonThatWasClicked == postfiltmodeButton)
    {
        //[UserButtonCode_postfiltmodeButton] -- add your button handler code here..
        //[/UserButtonCode_postfiltmodeButton]
    }
    else if (buttonThatWasClicked == undoBtn)
    {
        //[UserButtonCode_undoBtn] -- add your button handler code here..
        //[/UserButtonCode_undoBtn]
    }
    else if (buttonThatWasClicked == redoBtn)
    {
        //[UserButtonCode_redoBtn] -- add your button handler code here..
        //[/UserButtonCode_redoBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SimpleUI" componentName=""
                 parentClasses="public Component, ValueTree:Listener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="410" initialHeight="300">
  <BACKGROUND backgroundColour="ff8a2be2"/>
  <SLIDER name="new slider" id="acec880678ef6e57" memberName="clipSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0 100 100" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="clipLabel" id="682ad3bae7476279" memberName="clipLabel"
         virtualName="" explicitFocusOrder="0" pos="0 101 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="clip" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="bitsSlider" id="ee7fb301f540833d" memberName="bitsSlider"
          virtualName="" explicitFocusOrder="0" pos="101 0 100 100" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="bitsLabel" id="851f043c392e256b" memberName="bitsLabel"
         virtualName="" explicitFocusOrder="0" pos="101 101 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="bits" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="samplerateSlider" id="686b7b0c1d953fe7" memberName="samplerateSlider"
          virtualName="" explicitFocusOrder="0" pos="201 0 100 100" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="samplerateLabel" id="48d81609fb0f805f" memberName="samplerateLabel"
         virtualName="" explicitFocusOrder="0" pos="201 101 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="samplerate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="levelSlider" id="7f80e5be66bf9635" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="301 0 100 100" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="levelLabel" id="c78ca42caa64af57" memberName="levelLabel"
         virtualName="" explicitFocusOrder="0" pos="301 101 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="level" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="nonlinSlider" id="87c8af6b86672cd9" memberName="nonlinSlider"
          virtualName="" explicitFocusOrder="0" pos="0 125 100 100" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="nonlinLabel" id="a733b91d7a8cc88" memberName="nonlinLabel"
         virtualName="" explicitFocusOrder="0" pos="0 225 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="nonlin" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="postfiltSlider" id="ad2609fdaae35f08" memberName="postfiltSlider"
          virtualName="" explicitFocusOrder="0" pos="201 125 100 100" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="postfiltLabel" id="c6bd968cedb7a66" memberName="postfiltLabel"
         virtualName="" explicitFocusOrder="0" pos="201 225 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="postfilt" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="nonlinmodeButton" id="86b72e3effeebcda" memberName="nonlinmodeButton"
              virtualName="" explicitFocusOrder="0" pos="101 125 100 100" buttonText="S&lt;&gt;S&amp;H"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="postfiltmodeButton" id="a7c38483a1fe8979" memberName="postfiltmodeButton"
              virtualName="" explicitFocusOrder="0" pos="301 125 100 100" buttonText="Even/Odd"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GROUPCOMPONENT name="new group" id="abb7b51c44618e87" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 250 410 64" title="Preset Manager"
                  textpos="36"/>
  <TEXTBUTTON name="undoBtn" id="b57778b142966c03" memberName="undoBtn" virtualName=""
              explicitFocusOrder="0" pos="16 272 40 24" bgColOff="ffff0000"
              buttonText="undo" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="redoBtn" id="ad3a3b380a414d9d" memberName="redoBtn" virtualName=""
              explicitFocusOrder="0" pos="56 272 40 24" bgColOff="ff7fff00"
              buttonText="redo" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="6d63a38116c36354" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="104 272 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Last Action:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="actionText" id="f18115d051b893e1" memberName="actionText"
         virtualName="" explicitFocusOrder="0" pos="192 272 208 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
