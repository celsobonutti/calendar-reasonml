const purgecss = [
  '@fullhuman/postcss-purgecss', 
  {
  content: [
    "./components/**/**/*.re",
    "./pages/**/*.re"
  ],

  defaultExtractor: require("@dylanirlbeck/tailwind-ppx").extractor
  }
];

module.exports = {
  plugins: [
    'postcss-import',
    'tailwindcss',
    'autoprefixer',
    ...(process.env.NODE_ENV === "production" ? [purgecss] : [])
  ]
};