//
// Created by Jonathan Creasy on 6/14/18.
//

#include "Units.h"

Units::Units() = default;

Unit *Units::find_unit(long id) {
  Unit *unit_match = nullptr;

  for (auto &it : units) {
    auto *unit = (Unit *) it;

    if (unit->getId() == id) {
      unit_match = unit;
      break;
    }
  }
  return unit_match;
}

void Units::add(long id, UnitState state, Talkgroup *talkgroup) {
  auto *unit = new Unit(id, state, talkgroup);
  units.push_back(unit);
}

void Units::update_state(long id, UnitState state) {
  for (auto &it : units) {
    auto *unit = (Unit *) it;

    if (unit->getId() == id) {
      unit->setState(state);
      break;
    }
  }
}

void Units::update_talkgroup(long id, Talkgroup *talkgroup) {
  for (auto &it : units) {
    auto *unit = (Unit *) it;

    if (unit->getId() == id) {
      unit->setTalkgroup(talkgroup);
      break;
    }
  }
}

void Units::registration(long unit_id) {
  this->add(unit_id, on, nullptr);

  char shell_command[200];
  sprintf(shell_command, "./radiochange.sh %li on &", unit_id);
  system(shell_command);
}

void Units::deregistration(long unit_id) {
  this->update_state(unit_id, off);

  char shell_command[200];
  sprintf(shell_command, "./radiochange.sh %li off &", unit_id);
  system(shell_command);
}

void Units::affiliation(long unit_id, Talkgroup *talkgroup) {
  this->update_talkgroup(unit_id, talkgroup);

  char shell_command[200];
  sprintf(shell_command, "./radiochange.sh %li change %li &", unit_id, talkgroup->number);
  system(shell_command);
}