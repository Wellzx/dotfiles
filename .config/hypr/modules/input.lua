-- ██╗███╗   ██╗██████╗ ██╗   ██╗████████╗
-- ██║████╗  ██║██╔══██╗██║   ██║╚══██╔══╝
-- ██║██╔██╗ ██║██████╔╝██║   ██║   ██║
-- ██║██║╚██╗██║██╔═══╝ ██║   ██║   ██║
-- ██║██║ ╚████║██║     ╚██████╔╝   ██║
-- ╚═╝╚═╝  ╚═══╝╚═╝      ╚═════╝    ╚═╝
-----------------------------------------

hl.config({
    input = {
        kb_layout  = "us",
        kb_variant = "intl",
        kb_model   = "",
        kb_options = "lv3:lalt_switch",
        kb_rules   = "",

        repeat_rate = 50,
        repeat_delay = 250,

        follow_mouse = 1,

        sensitivity = 0,

        touchpad = {
            natural_scroll = false,
        },
    },
})

hl.gesture({
    fingers = 3,
    direction = "horizontal",
    action = "workspace"
})

hl.device({
    name        = "epic-mouse-v1",
    sensitivity = -0.5,
})
