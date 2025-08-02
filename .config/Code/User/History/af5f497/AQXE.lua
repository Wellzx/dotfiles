return {
  {
    "ellisonleao/gruvbox.nvim",
    priority = 1000,
    config = function()
      require("gruvbox").setup({ contrast = "hard" })
    end,
  },
  {
    "catppuccin/nvim",
    name = "catppuccin",
    priority = 1001,
    config = function()
      require("catppuccin").setup()
    end,
  },
}
