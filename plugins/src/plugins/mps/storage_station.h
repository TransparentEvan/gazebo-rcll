/***************************************************************************
 *  base_station.h - controls a basesation mps
 *
 *  Generated: Wed Apr 22 13:25:39 2015
 *  Copyright  2015  Randolph Maaßen
 *
 ****************************************************************************/

/*  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version. A runtime exception applies to
 *  this software (see LICENSE.GPL_WRE file mentioned below for details).
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  Read the full text in the LICENSE.GPL_WRE file in the doc directory.
 */

#ifndef STORAGESTATION_H
#define STORAGESTATION_H

#include "mps.h"

/// number of slots and shelfs
#define SLOT_X_COUNT 2
#define SLOT_Y_COUNT 4
#define SLOT_Z_COUNT 6
#define SHELF_POS_X 10
#define SHELF_POS_Y 10
#define SHELF_POS_Z 0


/// offsets for calculation of world pose slot positions
#define SLOT_X_OFFSET 0.1
#define SLOT_Y_OFFSET 0.2
#define SLOT_Z_OFFSET 0.4


namespace gazebo
{

class StorageStation : public Mps
{
public:
  StorageStation(physics::ModelPtr _parent, sdf::ElementPtr _sdf);
  ~StorageStation();
private:
  void on_puck_msg(ConstPosePtr &msg);
  void new_machine_info(ConstMachine &machine);
  void on_instruct_machine_msg(ConstInstructMachinePtr &msg);
  std::string have_puck_;
  
  void on_new_puck(ConstNewPuckPtr &msg);

  gzwrap::Pose3d get_slot_position(uint32_t slot_x, uint32_t slot_y, uint32_t slot_z);
  void init_storage();
  void store_puck(std::__cxx11::string puck_name, uint32_t slot_pos_x, uint32_t slot_pos_y, uint32_t slot_pos_z);
  void retrieve_puck(uint32_t slot_pos_x, uint32_t slot_pos_y, uint32_t slot_pos_z);

  void addCap(physics::ModelPtr puck,gazsim_msgs::Color clr);
  void addRing();

  /// position of the first shelf first slot logic coords: (0,0,0)
  double shelf_pos_x;
  double shelf_pos_y;
  double shelf_pos_z;

  /// offset to reach each consecutive slot. Multiply these n times the logic slot
  double shelf_x_offset;
  double shelf_y_offset;
  double shelf_z_offset;

  std::string* storage_;
  int storage_cnt;


};

}
#endif // STORAGETATION_H
