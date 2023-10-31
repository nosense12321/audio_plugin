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

        // add items to the combo-box
        addAndMakeVisible(styleMenu);
        styleMenu.addItem("Room", 1);
        styleMenu.addItem("Hall", 2);
        styleMenu.addItem("Plate", 3);
        styleMenu.addItem("Nonlinear", 4);
        styleMenu.addItem("Custom", 5);

        addAndMakeVisible(dial1);
        addAndMakeVisible(dial2);

        dial1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
        dial2.setSliderStyle(juce::Slider::SliderStyle::Rotary);

        dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
        dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);

        //styleMenu.onChange = [this] { styleMenuChanged(); };
        //styleMenu.setSelectedId(styleBold);
        setSize(400, 200);
    }

    void resized() override
    {
        textLabel.setBounds(10, 5, getWidth() - 10, 40);
        styleMenu.setBounds(10, 50, getWidth() - 50, 40);

        const int border = 10;
        const int dialWidth = getWidth() / 2 - 150;
        const int dialHeight = getHeight() / 2;

        dial1.setBounds(border, border * 15, dialWidth, dialHeight);
        dial2.setBounds(border * 50, border * 15, dialWidth, dialHeight);
    }

private:
    void styleMenuChanged()
    {
        /*switch (styleMenu.getSelectedId())
        {
        case stylePlain: textFont.setStyleFlags(juce::Font::plain);  break;
        case styleBold: textFont.setStyleFlags(juce::Font::bold);   break;
        case styleItalic: textFont.setStyleFlags(juce::Font::italic); break;
        default: break;
        }*/

        textLabel.setFont(textFont);
    }


    enum ReverbStyles
    {
        Room = 1,
        Hall,
        Plate,
        Nonlinear,
        Custom
    };

    enum TextColours
    {
        black = 1,
        white,
        red,
        darkred,
        indianred,
        green,
        darkgreen,
        lightgreen,
        blue,
        darkblue,
        lightblue,
        numberOfColours
    };

    //==============================================================================
    juce::Label textLabel{ {}, "Choose the reverb type" };
    juce::Font textFont{ 30.0f };
    juce::ComboBox styleMenu;

    juce::Slider dial1;
    juce::Slider dial2;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
};
