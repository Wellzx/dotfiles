return {
  {
    "ellisonleao/gruvbox.nvim",
    priority = 1000, -- carrega antes dos outros
    config = function()
      require("gruvbox").setup({
        terminal_colors = true,
        contrast = "hard", -- "soft", "hard" ou ""
        transparent_mode = false,
      })
      vim.o.background = "dark" -- ou "light"
      vim.cmd([[colorscheme gruvbox]])
    end,
  },
}
