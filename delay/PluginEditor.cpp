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
    sliderFeedback.setValue(0.0f);
    sliderFeedback.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    sliderFeedback.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    sliderFeedback.addListener(this);

    addAndMakeVisible(sliderVolume);
    sliderVolume.setRange(0.0, 2.0);
    sliderVolume.setValue(1.0);
    sliderVolume.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    sliderVolume.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sliderVolume.addListener(this);

    addAndMakeVisible(button);
    button.onClick = [this]() { off(); };

    addAndMakeVisible(styleMenu);
    styleMenu.addItem("Max", 1);
    styleMenu.addItem("Min", 2);
    styleMenu.onChange = [this] { styleMenuChanged(); };
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
    sliderDelayMs.setBounds(getLocalBounds().removeFromBottom(getWidth() / 3) / 1.4);
    sliderFeedback.setBounds(getLocalBounds().removeFromTop(getWidth() / 3) / 1.4);
    sliderVolume.setBounds(getLocalBounds().removeFromRight(getWidth() / 3) / 1.4);
    button.setBounds(getLocalBounds().removeFromBottom(getWidth() / 5));
    styleMenu.setBounds(getLocalBounds().removeFromTop(getWidth() / 10).removeFromRight(getWidth() / 3));
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

void NewProjectAudioProcessorEditor::off() {
    audioProcessor.changeDelayMs = 0.0f;
    sliderDelayMs.setValue(0.0f);
    audioProcessor.changeFeedback = 0.0f;
    sliderFeedback.setValue(0.0f);
    audioProcessor.changeVolume = 1.0;
    sliderVolume.setValue(1.0);
}

void NewProjectAudioProcessorEditor::styleMenuChanged()
{
    switch (styleMenu.getSelectedId())
    {
    case 1: audioProcessor.changeDelayMs = 1.0f;
            audioProcessor.changeFeedback = 1.0f;
            audioProcessor.changeVolume = 2.0;
            break;
    case 2: audioProcessor.changeDelayMs = 0.0f;
            audioProcessor.changeFeedback = 0.0f;
            audioProcessor.changeVolume = 0.0;
            break;
    default: break;
    }
    sliderDelayMs.setValue(audioProcessor.changeDelayMs);
    sliderFeedback.setValue(audioProcessor.changeFeedback);
    sliderVolume.setValue(audioProcessor.changeVolume);
}