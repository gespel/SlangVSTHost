/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SlangHostAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SlangHostAudioProcessorEditor (SlangHostAudioProcessor&);
    ~SlangHostAudioProcessorEditor() override;
    juce::TextEditor input;
    juce::TextButton programApply{"Apply Program"};
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SlangHostAudioProcessor& audioProcessor;
    
    void applyProgram();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlangHostAudioProcessorEditor)
};
