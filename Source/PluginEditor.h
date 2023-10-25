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
class GainControlAudioProcessorEditor : public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:

    void sliderValueChanged(juce::Slider* slider) override;

    GainControlAudioProcessorEditor(GainControlAudioProcessor&);
    ~GainControlAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainControlAudioProcessor& audioProcessor;

    juce::Slider gainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainControlAudioProcessorEditor)
};
