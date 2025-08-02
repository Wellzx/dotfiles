-- ~/.config/nvim/lua/config/colorscheme.lua

local M = {}

local colorscheme_file = vim.fn.stdpath("config") .. "/colorscheme.txt"

local function load_saved_colorscheme()
  local f = io.open(colorscheme_file, "r")
  if f then
    local theme = f:read("*l")
    f:close()
    if theme then
      local ok, _ = pcall(vim.cmd, "colorscheme " .. theme)
      if not ok then
        vim.cmd("colorscheme gruvbox") -- fallback
      end
    else
      vim.cmd("colorscheme gruvbox") -- fallback
    end
  else
    vim.cmd("colorscheme gruvbox") -- fallback
  end
end

local function save_colorscheme(theme)
  local f = io.open(colorscheme_file, "w")
  if f then
    f:write(theme)
    f:close()
  end
end

function M.setup()
  load_saved_colorscheme()

  vim.api.nvim_create_user_command("Theme", function(opts)
    local ok, _ = pcall(vim.cmd, "colorscheme " .. opts.args)
    if ok then
      save_colorscheme(opts.args)
      print("Tema salvo: " .. opts.args)
    else
      print("Tema não encontrado: " .. opts.args)
    end
  end, { nargs = 1 })
end

return M
