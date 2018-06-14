//
// Created by Jonathan Creasy on 6/14/18.
//

#include "Unit.h"

Unit::Unit(long id, UnitState state, Talkgroup *talkgroup) : id(id), state(state), talkgroup(talkgroup) {
  this->id = id;
  this->state = state;
  this->talkgroup = talkgroup;
}

long Unit::getId() const {
  return id;
}

void Unit::setId(long id) {
  Unit::id = id;
}

UnitState Unit::getState() const {
  return state;
}

void Unit::setState(UnitState state) {
  Unit::state = state;
}

Talkgroup *Unit::getTalkgroup() const {
  return talkgroup;
}

void Unit::setTalkgroup(Talkgroup *talkgroup) {
  Unit::talkgroup = talkgroup;
}
