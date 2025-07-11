export default {
  extends: ['@commitlint/config-conventional'],
  rules: {
    'header-max-length': [1, 'always', 200],
    'body-max-line-length': [1, 'always', Infinity],
    'type-enum': [
      2,
      'always',
      [
        'feat', // Adds a new user-facing feature
        'fix', // Fixes a user-facing bug
        'docs', // Updates or adds documentation
        'style', // Code formatting changes without functional impact
        'refactor', // Code changes without altering functionality
        'test', // Adds or updates tests
        'chore', // Updates build tools or dependencies without functional impact
        'perf', // Enhances performance or efficiency
        'vendor', // Updates dependency versions
        'build', // Changes to the build system or dependencies
        'ci', // Updates CI configurations or scripts
        'revert', // Reverts a previous commit
        'release', // Creates a new release
      ],
    ],
  },
};
