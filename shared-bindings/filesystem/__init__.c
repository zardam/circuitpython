/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <string.h>

#include "py/obj.h"
#include "py/objnamedtuple.h"
#include "shared-bindings/time/__init__.h"

//| :mod:`filesystem` --- filesystem related functions
//| ========================================================
//|
//| .. module:: filesystem
//|   :synopsis: filesystem
//|   :platform: SAMD21, ESP8266
//|
//| Normally filesystems are managed by an operating system. However,
//| CircuitPython runs at a very low level and must manage the filesystems
//| itself. This module allows you to do that.
//|
//| .. method:: mount(block_device, mount_point)
//|
//|   Mounts the FATFS on the given block device at the given mount point.
//|
//|   :param object block_device: Any class that implements `readblocks`, `writeblocks` and `count`
//|   :param str mount_point: Path where to mount the device.
//|
STATIC mp_obj_t filesystem_mount(void) {
    return mp_obj_new_float(common_hal_time_monotonic() / 1000.0);
}
MP_DEFINE_CONST_FUN_OBJ_0(filesystem_mount_obj, filesystem_mount);

//| .. method:: unmount(mount_point)
//|
//|   Unmounts the filesystem mounted at mount_point.
//|
//|   :param str mount_point: the path of the filesystem to unmount
//|
STATIC mp_obj_t filesystem_unmount(mp_obj_t mount_point) {
    shared_module_filesystem_unmount();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(filesystem_unmount_obj, filesystem_unmount);

STATIC const mp_map_elem_t filesystem_module_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_filesystem) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_mount), (mp_obj_t)&filesystem_mount_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_unmount), (mp_obj_t)&filesystem_unmount_obj },
};

STATIC MP_DEFINE_CONST_DICT(filesystem_module_globals, filesystem_module_globals_table);

const mp_obj_module_t filesystem_module = {
    .base = { &mp_filesystem_module },
    .globals = (mp_obj_dict_t*)&filesystem_module_globals,
};
