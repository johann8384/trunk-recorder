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
