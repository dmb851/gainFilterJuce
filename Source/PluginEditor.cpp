#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyGainAudioProcessorEditor::MyGainAudioProcessorEditor (MyGainAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    //gainSlider.setRange(-60.0f, 0.0f, 0.01f);
    //gainSlider.setValue(-20.0f);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    
    //Try to change the color id to the actual enumeration ie. 0x1001310 to trackColorId
    gainSlider.setColour(0x1001310,Colours::greenyellow);
    gainSlider.setColour(0x1001300, Colours::aquamarine);
   
    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts, "GAIN", gainSlider);
    titleLabel.setText("Xpressound",dontSendNotification);
    //gainSlider.addListener(this);
    addAndMakeVisible(titleLabel);
    addAndMakeVisible(gainSlider);
    setSize(200, 600);
}

MyGainAudioProcessorEditor::~MyGainAudioProcessorEditor()
{
}

//==============================================================================
void MyGainAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::black);
    Image background = ImageCache::getFromMemory(BinaryData::resizedimagePromo_1_jpeg, BinaryData::resizedimagePromo_1_jpegSize);
    
    g.drawImageAt(background, 0, 0);
   
}

void MyGainAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 -50, getHeight() / 6 - 75 , 100, 500);
    titleLabel.setBounds(getWidth() / 4 - 50, getHeight() - 100, 200, 150);
}







