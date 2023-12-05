#include "PluginProcessor.h"
#include "PluginEditor.h"


DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    addAndMakeVisible(sliderDistortion);
    sliderDistortion.setRange(0.07f, 1.0f);
    sliderDistortion.setValue(1.0f);
    sliderDistortion.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    sliderDistortion.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    sliderDistortion.addListener(this);

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

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::aquamarine);
}

void DistortionAudioProcessorEditor::resized()
{
    
    sliderDistortion.setBounds(getLocalBounds().removeFromLeft(getWidth() / 2) / 1.5);
    sliderVolume.setBounds(getLocalBounds().removeFromRight(getWidth() / 2) / 1.5);
    button.setBounds(getLocalBounds().removeFromBottom(getWidth() / 5));
    styleMenu.setBounds(getLocalBounds().removeFromTop(getWidth() / 10).removeFromRight(getWidth()/3));
}

void DistortionAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
    if (slider == &sliderDistortion) {
        audioProcessor.changeDistortion = sliderDistortion.getValue();
    }
    if (slider == &sliderVolume) {
        audioProcessor.changeVolume = sliderVolume.getValue();
    }
}

void DistortionAudioProcessorEditor::off() {
    audioProcessor.changeDistortion = 1.0f;
    sliderDistortion.setValue(1.0f);
    audioProcessor.changeVolume = 1.0;
    sliderVolume.setValue(1.0);
}

void DistortionAudioProcessorEditor::styleMenuChanged() 
{
    switch (styleMenu.getSelectedId()) 
    {
    case 1: audioProcessor.changeDistortion = 1.0f;
            audioProcessor.changeVolume = 2.0;
            break;
    case 2: audioProcessor.changeDistortion = 0.07f;
            audioProcessor.changeVolume = 0.0;
            break;
    default: break;
    }
    sliderDistortion.setValue(audioProcessor.changeDistortion);
    sliderVolume.setValue(audioProcessor.changeVolume);
}
