OLED_ENABLE = no
OLED_DRIVER = SSD1306

COMBO_ENABLE = no
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = no
MOUSEKEY_ENABLE = yes

SRC += features/layer_lock.c

# BONGO_ENABLED = yes
# LUNA_ENABLED  = yes
# WPM_ENABLE    = yes

# ifeq ($(OLED_ENABLE),yes)
# 	SRC += ./oled.c \
# 	SRC += ./luna.c
# endif

# SRC += ./luna.c
