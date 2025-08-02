-- ~/.config/nvim/lua/plugins/colorscheme.lua
return {
  {
    "ellisonleao/gruvbox.nvim",
    priority = 1000,
    config = function()
      require("gruvbox").setup({
        terminal_colors = true,
        contrast = "hard",
        transparent_mode = false,
      })
      vim.o.background = "dark"
      vim.cmd([[colorscheme gruvbox]])
    end,
  },
}
