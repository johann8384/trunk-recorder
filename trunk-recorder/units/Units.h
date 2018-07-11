//
// Created by Jonathan Creasy on 6/14/18.
//

#ifndef TRUNK_RECORDER_UNITS_H
#define TRUNK_RECORDER_UNITS_H


#include <string>
#include <vector>
#include "Unit.h"

class Units {
  std::vector<Unit *> units;

public:
  Units();

  Unit *find_unit(long id);

  void add(long id, UnitState state, Talkgroup *talkgroup);

  void update_state(long id, UnitState state);

  void update_talkgroup(long id, Talkgroup *talkgroup);

  void registration(long unit_id);

  void deregistration(long unit_id);

  void affiliation(long unit_id, Talkgroup *talkgroup);
};

#endif //TRUNK_RECORDER_UNITS_H
