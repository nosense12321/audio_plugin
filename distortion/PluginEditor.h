#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class DistortionAudioProcessorEditor  : public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:
    void sliderValueChanged(juce::Slider* slider) override;
    DistortionAudioProcessorEditor (DistortionAudioProcessor&);
    ~DistortionAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void DistortionAudioProcessorEditor::off();
    void DistortionAudioProcessorEditor::styleMenuChanged();

private:
    DistortionAudioProcessor& audioProcessor;

    juce::Slider sliderDistortion;
    juce::Slider sliderVolume;
    juce::TextButton button {"OFF"};
    juce::ComboBox styleMenu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionAudioProcessorEditor)
};
