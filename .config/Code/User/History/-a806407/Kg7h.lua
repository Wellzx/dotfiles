function M.setup()
  vim.api.nvim_create_autocmd("VimEnter", {
    callback = function()
      load_saved_colorscheme()
    end,
  })

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
