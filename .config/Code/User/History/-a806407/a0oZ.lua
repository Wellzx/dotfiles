local M = {}

local colorscheme_file = vim.fn.stdpath("config") .. "/colorscheme.txt"

local function load_saved_colorscheme()
  local f = io.open(colorscheme_file, "r")
  if f then
    local theme = f:read("*l")
    f:close()
    if theme then
      local ok, err = pcall(vim.cmd, "colorscheme " .. theme)
      if not ok then
        print("Erro ao carregar tema salvo: " .. theme .. "\n" .. (err or "erro desconhecido"))
        -- NÃO coloca fallback aqui, fica no tema atual (default do Neovim)
      end
    else
      print("Arquivo de tema salvo vazio.")
      -- Também não muda nada
    end
  else
    print("Arquivo de tema salvo não encontrado.")
    -- Não muda nada, fica padrão
  end
end

function M.setup()
  vim.api.nvim_create_autocmd("User", {
    pattern = "LazyDone",
    callback = function()
      load_saved_colorscheme()
    end,
  })

  vim.api.nvim_create_user_command("Theme", function(opts)
    local ok, err = pcall(vim.cmd, "colorscheme " .. opts.args)
    if ok then
      local f = io.open(colorscheme_file, "w")
      if f then
        f:write(opts.args)
        f:close()
      end
      print("Tema salvo: " .. opts.args)
    else
      print("Tema não encontrado: " .. opts.args .. "\n" .. (err or "erro desconhecido"))
    end
  end, { nargs = 1 })
end

return M
