-- ~/.config/nvim/lua/config/dashboard.lua

local alpha = require("alpha")
local dashboard = require("alpha.themes.dashboard")

dashboard.section.header.val = {
  "██╗    ██╗███████╗██╗         ",
  "██║    ██║██╔════╝██║         ",
  "██║ █╗ ██║█████╗  ██║         ",
  "██║███╗██║██╔══╝  ██║         ",
  "╚███╔███╔╝███████╗███████╗    ",
  " ╚══╝╚══╝ ╚══════╝╚══════╝    ",
  "     Wel Apelão 🚀🔥",
}

alpha.setup(dashboard.opts)
