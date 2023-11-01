/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================

NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);

    addAndMakeVisible(gainSlider1);
    gainSlider1.setRange(0.0f, 1.0f);
    gainSlider1.setValue(0.0f);
    gainSlider1.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    gainSlider1.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider1.addListener(this);

    addAndMakeVisible(gainSlider2);
    gainSlider2.setRange(0.0f, 1.0f);
    gainSlider2.setValue(0.0f);
    gainSlider2.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    gainSlider2.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider2.addListener(this);

    addAndMakeVisible(gainSlider3);
    gainSlider3.setRange(0.0, 2.0);
    gainSlider3.setValue(1.0);
    gainSlider3.setTextBoxStyle(juce::Slider::TextBoxBelow, 0, 100, 20);
    gainSlider3.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider3.addListener(this);

    /*
    addAndMakeVisible(label1);
    label1.setText("Delay Ms", juce::dontSendNotification);
    label1.attachToComponent(&gainSlider1, true);
    addAndMakeVisible(label2);
    label2.setText("Feedback", juce::dontSendNotification);
    label2.attachToComponent(&gainSlider2, true);
    */
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
    gainSlider1.setBounds(getLocalBounds().removeFromTop(getWidth() / 4));
    gainSlider2.setBounds(getLocalBounds().removeFromBottom(getWidth() / 4));
    gainSlider3.setBounds(getLocalBounds().removeFromRight(getWidth() / 4));
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider1) {
        audioProcessor.gainChange = gainSlider1.getValue();
    }
    if (slider == &gainSlider2) {
        audioProcessor.gainChange2 = gainSlider2.getValue();
    }
    if (slider == &gainSlider3) {
        audioProcessor.gainChange3 = gainSlider3.getValue();
    }
}
