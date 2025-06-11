/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SlangHostAudioProcessorEditor::SlangHostAudioProcessorEditor (SlangHostAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    input.setMultiLine(true);
    input.setReturnKeyStartsNewLine(true);
    input.setTabKeyUsedAsCharacter(true);
    addAndMakeVisible(input);
    programApply.onClick = [this]() {
        applyProgram();
    };
    programApply.setToggleState(true, juce::NotificationType::dontSendNotification);
    addAndMakeVisible(programApply);
    setSize (600, 400);
}

SlangHostAudioProcessorEditor::~SlangHostAudioProcessorEditor()
{
}

void SlangHostAudioProcessorEditor::applyProgram() {
    int l = 0;
    audioProcessor.si = createSlangInterpreter(tokenize((char *)input.getText().toStdString().c_str(), &l), l);
    interpret(audioProcessor.si);
    audioProcessor.sbc = createBufferCore(audioProcessor.si, 512);
}

//==============================================================================
void SlangHostAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);

    g.setColour (juce::Colours::black);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SlangHostAudioProcessorEditor::resized()
{
    input.setBounds(10, 10, 580, 350);
    programApply.setBounds(10, 365, 290, 30);
}
