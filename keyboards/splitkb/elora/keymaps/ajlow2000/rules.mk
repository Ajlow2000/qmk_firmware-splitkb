# Copyright 2023 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Note: this list is not exhaustive!
# See https://docs.qmk.fm for more features

## Hardware features

OLED_ENABLE = yes

# Audio: optional, requires soldering
# The Elora is equipped with a footprint
# for the PKLCS1212E4001-R1
AUDIO_ENABLE = no          # Enable audio support, `yes` or `no`

## Software features

# Supported keycodes
MOUSEKEY_ENABLE = yes      # Mouse movement using keys
EXTRAKEY_ENABLE = yes      # Audio and system control

# N-key rollover instead of 6-key rollover
NKRO_ENABLE = yes          # Enable N-Key Rollover

TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
