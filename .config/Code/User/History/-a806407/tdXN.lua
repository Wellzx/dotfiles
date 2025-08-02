-- ~/.config/nvim/lua/config/colorscheme.lua

local M = {}

function M.setup()
  local theme = "tokyonight" -- troque aqui!

  if theme == "gruvbox" then
    require("gruvbox").setup({
      contrast = "hard",
      transparent_mode = false,
    })

  elseif theme == "catppuccin" then
    require("catppuccin").setup({
      flavour = "mocha",
      transparent_background = true,
    })

  elseif theme == "tokyonight" then
    require("tokyonight").setup({
      style = "storm",
      transparent = false,
    })
  end

  vim.o.background = "dark"
  vim.cmd("colorscheme " .. theme)
end

return M
