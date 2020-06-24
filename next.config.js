const withTM = require('next-transpile-modules')(['bs-platform', 're-classnames', 'decco'])

module.exports = withTM({
  pageExtensions: ['jsx', 'js', 'bs.js'],
})
