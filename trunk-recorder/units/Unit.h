//
// Created by Jonathan Creasy on 6/14/18.
//

#ifndef TRUNK_RECORDER_UNIT_H
#define TRUNK_RECORDER_UNIT_H

#include "../talkgroup.h"
#include "UnitState.h"
#include "../state.h"
#include <string>

class Unit {
public:
  Unit(long id, UnitState state, Talkgroup *talkgroup);

  long getId() const;

  void setId(long id);

  UnitState getState() const;

  void setState(UnitState state);

  Talkgroup *getTalkgroup() const;

  void setTalkgroup(Talkgroup *talkgroup);

  std::string unit();

private:
  long id;
  UnitState state;
  Talkgroup *talkgroup;
};

#endif //TRUNK_RECORDER_UNIT_H
