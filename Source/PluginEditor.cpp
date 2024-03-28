/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TestTake2AudioProcessorEditor::TestTake2AudioProcessorEditor (TestTake2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 50, 20);
    gainSlider.setRange(0.0f, 1.0f, 0.01f);
    gainSlider.setValue(0.5f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    // Initialize pitch shift slider
    pitchShiftSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    pitchShiftSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 50, 20);
    pitchShiftSlider.setRange(-6.0f, 6.0f, 0.1f); // Adjust range as needed
    pitchShiftSlider.setValue(0.0f); // Set default value
    pitchShiftSlider.addListener(this);
    addAndMakeVisible(pitchShiftSlider);

    setSize(400, 300);
}

TestTake2AudioProcessorEditor::~TestTake2AudioProcessorEditor()
{
}

//==============================================================================
void TestTake2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (30.0f);
//    g.drawFittedText ("Gain", getLocalBounds(), juce::Justification::centred, 1);
    g.drawFittedText("Gain Slider", 70, 110, 100, 300, juce::Justification::centred, 1);
    g.drawFittedText("Pitch Slider", 70, 110, 450, 300, juce::Justification::centred, 1);
    gainSlider.setBounds(50, getHeight() / 2 - 100, 100, 200);
    pitchShiftSlider.setBounds(250, getHeight() / 2 - 100, 100, 200); // Adjust position as needed
}

void TestTake2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void TestTake2AudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider) {
        audioProcessor.rawVolume = gainSlider.getValue();
    }
//    else if (slider == &pitchShiftSlider) {
//        // Update pitch shift value
//        audioProcessor.setPitchShift(pitchShiftSlider.getValue());
//    }
//}
    else if (slider == &pitchShiftSlider) {
        // Update pitch shift value in audio processor
        audioProcessor.setPitchShift(pitchShiftSlider.getValue());
    }
}
