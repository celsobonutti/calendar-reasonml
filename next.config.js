const withTM = require('next-transpile-modules')(['bs-platform', 're-classnames', 'decco', 'bs-reform', 'reschema', 'lenses-ppx', 'reason-react-update'])

module.exports = withTM({
  pageExtensions: ['jsx', 'js', 'bs.js'],
})
