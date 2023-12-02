#include "PluginProcessor.h"
#include "PluginEditor.h"


NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 300);

    addAndMakeVisible(sliderDelayMs);
    sliderDelayMs.setRange(0.0f, 1.0f);
    sliderDelayMs.setValue(0.0f);
    sliderDelayMs.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    sliderDelayMs.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    sliderDelayMs.addListener(this);

    addAndMakeVisible(sliderFeedback);
    sliderFeedback.setRange(0.0f, 1.0f);
    sliderFeedback.setValue(0.7f);
    sliderFeedback.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    sliderFeedback.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    sliderFeedback.addListener(this);

    addAndMakeVisible(sliderVolume);
    sliderVolume.setRange(0.0, 2.0);
    sliderVolume.setValue(1.0);
    sliderVolume.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    sliderVolume.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sliderVolume.addListener(this);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::aquamarine);
}

void NewProjectAudioProcessorEditor::resized()
{
    sliderDelayMs.setBounds(getLocalBounds().removeFromTop(getWidth() / 4));
    sliderFeedback.setBounds(getLocalBounds().removeFromBottom(getWidth() / 4));
    sliderVolume.setBounds(getLocalBounds().removeFromRight(getWidth() / 4));
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &sliderDelayMs) {
        audioProcessor.changeDelayMs = sliderDelayMs.getValue();
    }
    if (slider == &sliderFeedback) {
        audioProcessor.changeFeedback = sliderFeedback.getValue();
    }
    if (slider == &sliderVolume) {
        audioProcessor.changeVolume = sliderVolume.getValue();
    }
}