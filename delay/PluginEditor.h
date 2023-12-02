#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================

class NewProjectAudioProcessorEditor : public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:
    void sliderValueChanged(juce::Slider* slider) override;
    NewProjectAudioProcessorEditor(NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void NewProjectAudioProcessorEditor::off();

private:
    NewProjectAudioProcessor& audioProcessor;

    juce::Slider sliderDelayMs;
    juce::Slider sliderFeedback;
    juce::Slider sliderVolume;
    juce::TextButton button{ "OFF" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessorEditor)
};

