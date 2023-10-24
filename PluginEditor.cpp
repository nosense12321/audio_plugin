/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================

NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);

    addAndMakeVisible(gainSlider);
    gainSlider.setRange(0.0, 1.0);
    gainSlider.setValue(0.5);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider2);
    gainSlider2.setRange(0.0, 1.0);
    gainSlider2.setValue(0.5);
    gainSlider2.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    gainSlider2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    gainSlider2.addListener(this);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::aquamarine);

}

void NewProjectAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds().removeFromLeft(getWidth()/2));
    gainSlider2.setBounds(getLocalBounds().removeFromRight(getWidth() / 2));
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider) {
        audioProcessor.gainChange = gainSlider.getValue();
    }
    if (slider == &gainSlider2) {
        audioProcessor.gainChange2 = gainSlider2.getValue();
    }
}
