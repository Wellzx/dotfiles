return {
  "goolord/alpha-nvim",
  dependencies = { "nvim-tree/nvim-web-devicons" },
  event = "VimEnter",
  config = function()
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

    dashboard.section.buttons.val = {
      dashboard.button("e", "📄  Novo Arquivo", ":ene <BAR> startinsert <CR>"),
      dashboard.button("f", "🔍  Procurar Arquivo", ":Telescope find_files<CR>"),
      dashboard.button("q", "❌  Sair", ":qa<CR>"),
    }

    dashboard.section.footer.val = "Jesus é o centro de tudo! 🙏"

    alpha.setup(dashboard.opts)
  end,
}
