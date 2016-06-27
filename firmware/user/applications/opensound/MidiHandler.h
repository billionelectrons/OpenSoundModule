#ifndef _MidiHandler_HPP_
#define _MidiHandler_HPP_

#include <stdint.h>
#define NOF_PARAMETERS               24
#define MIDI_CHANNEL                 0
#define MIDI_MAX_MESSAGE_SIZE        256

class MidiHandler {
private:
  int16_t midi_values[NOF_PARAMETERS];
public:
  MidiHandler();
  void handleProgramChange(uint8_t status, uint8_t pc);
  void handleControlChange(uint8_t status, uint8_t cc, uint8_t value);
  void handleNoteOff(uint8_t status, uint8_t note, uint8_t velocity);
  void handleNoteOn(uint8_t status, uint8_t note, uint8_t velocity);
  void handlePitchBend(uint8_t status, uint16_t value);
  void handleSysEx(uint8_t* data, uint16_t size);

  void handleSystemCommon(uint8_t cmd){}
  void handleSystemCommon(uint8_t cmd1, uint8_t cmd2){}
  void handleSystemCommon(uint8_t cmd1, uint8_t cmd2, uint8_t cmd3){}
  void handleChannelPressure(uint8_t status, uint8_t value){}
  void handlePolyKeyPressure(uint8_t status, uint8_t note, uint8_t value){}

private:
  void handleConfigurationCommand(uint8_t* data, uint16_t size);
  void handleFirmwareUploadCommand(uint8_t* data, uint16_t size);
  void handleFirmwareRunCommand(uint8_t* data, uint16_t size);
  void handleFirmwareFlashCommand(uint8_t* data, uint16_t size);
  void handleFirmwareStoreCommand(uint8_t* data, uint16_t size);

};

#endif /* _MidiHandler_HPP_ */
