#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public juce::Component
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible(textLabel);
        textLabel.setFont(textFont);
        textLabel.setColour(juce::Label::textColourId, juce::Colour (230, 231, 242));

        // add items to the combo-box
        addAndMakeVisible(styleMenu);
        styleMenu.addItem("Room", 1);
        styleMenu.addItem("Hall", 2);
        styleMenu.addItem("Plate", 3);
        styleMenu.addItem("Nonlinear", 4);
        styleMenu.addItem("Custom", 5);

        addAndMakeVisible(dial1);
        addAndMakeVisible(dial2);
        addAndMakeVisible(dial3);
        addAndMakeVisible(dial4);
        addAndMakeVisible(dial5);

        dial1.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        dial2.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        dial3.setSliderStyle(juce::Slider::SliderStyle::Rotary);
        dial4.setSliderStyle(juce::Slider::SliderStyle::Rotary);
        dial5.setSliderStyle(juce::Slider::SliderStyle::Rotary);
     

        dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
        dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
        dial3.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
        dial4.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
        dial5.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
      

        getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colour(230, 231, 242));

        //styleMenu.onChange = [this] { styleMenuChanged(); };
        //styleMenu.setSelectedId(styleBold);
        //setSize(100, 100);
    }

    void paint(juce::Graphics& g) override
    {
        // Set the background color to black
        g.setColour(juce::Colour (62, 52, 66));

        // Fill the entire component with the specified color
        g.fillRect(getLocalBounds());

        //juce::Font theFont("Cooper Std", "Black Italic", 25.0f);
        //g.setFont(theFont);
        //g.drawText("Choose the reverb style", 10, 10, 400, 60, juce::Justification::topLeft);
        // You may want to add additional painting code here if needed
    }

    void resized() override
    {
        textLabel.setBounds(10, getHeight() / 100, getWidth() - 100, 40);
        styleMenu.setBounds(18, getHeight()/11, getWidth() / 3 - getWidth()/5, 30);

        const int border = 10;
        const int dialRotaryWidth = getWidth() / 2 - 150;
        const int dialRotaryHeight = getHeight() / 2;
        const int dialLinearWidth = getWidth() / 2 - 90;
        const int dialLinearHeight = getHeight() / 1.5;

        dial1.setBounds(border - 80, border * 8, dialLinearWidth, dialLinearHeight);
        dial2.setBounds(border * 10, border * 8, dialLinearWidth, dialLinearHeight);
        dial3.setBounds(border * 35, border - 10, dialRotaryWidth, dialRotaryHeight);
        dial4.setBounds(border * 58, border * 10, dialRotaryWidth, dialRotaryHeight);
        dial5.setBounds(border * 35, border * 22, dialRotaryWidth, dialRotaryHeight);
        
    }

private:
    void styleMenuChanged()
    {

       // textLabel.setFont(textFont);
    }


    enum ReverbStyles
    {
        Room = 1,
        Hall,
        Plate,
        Nonlinear,
        Custom
    };

    float fontSize = float(getHeight() / 10);
    //==============================================================================
    juce::Label textLabel{ {}, "Choose the reverb type" };
    juce::Font textFont{ (21.0f) };
    juce::ComboBox styleMenu;

    juce::Slider dial1;
    juce::Slider dial2;
    juce::Slider dial3;
    juce::Slider dial4;
    juce::Slider dial5;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
};
