-- ~/.config/nvim/lua/config/colorscheme.lua

local M = {}

function M.setup()
  vim.o.background = "dark" -- ou "light", se preferir

  -- Se estiver usando gruvbox:
  vim.cmd("colorscheme gruvbox")
end

return M
