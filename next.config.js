const withTM = require('next-transpile-modules')(['bs-platform', 're-classnames'])

module.exports = withTM({
  pageExtensions: ['jsx', 'js', 'bs.js'],
})
