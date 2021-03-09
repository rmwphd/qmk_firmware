SRC += rmw.c

ifdef TAP_DANCE_ENABLE
SRC += tapdances.c
endif

ifdef ENCODER_ENABLE
SRC += encoder_functions.c
endif

ifdef COMBO_ENABLE
SRC += combos.c
endif
