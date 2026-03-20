# SCSS Build Process for Custom New Year Module

## Overview
This module uses SCSS for organized CSS development. The source files are in the `css/` directory and need to be compiled to CSS for Drupal to use.

## Directory Structure
```
css/
├── styles.scss              # Main SCSS entry point
├── _variables.scss          # SCSS variables (colors, sizes, etc.)
├── _mixins.scss            # SCSS mixins for reusable code
├── components/
│   └── _lightrope.scss     # Main lightrope component styles
├── _theme-overrides.scss   # Theme-specific overrides
├── lightrope.css           # Compiled CSS (used by Drupal)
└── libs/                   # Third-party SCSS libraries (if any)
```

## Requirements
- Node.js with npm/yarn
- Sass compiler (sass/dart-sass or node-sass)
- Optional: SCSS livereload tool for development

## Installation of Build Tools

### Option 1: Global Sass Installation
```bash
# Install Sass globally
npm install -g sass

# Or use Yarn
yarn global add sass
```

### Option 2: Local Development Setup
```bash
# Initialize npm project in the css directory
cd css
npm init -y

# Install sass as dev dependency
npm install --save-dev sass

# Or with yarn
yarn add --dev sass
```

## Build Commands

### Manual Compilation
```bash
# Compile all SCSS files to CSS
sass styles.scss lightrope.css --style compressed

# For development (uncompressed, with source maps)
sass styles.scss lightrope.css --style expanded --source-map

# Watch for changes (auto-recompile)
sass styles.scss lightrope.css --watch --source-map
```

### Automated Build Script
Create a `package.json` in the css directory:
```json
{
  "name": "custom-newyear-css",
  "version": "1.0.0",
  "scripts": {
    "build": "sass styles.scss lightrope.css --style compressed",
    "dev": "sass styles.scss lightrope.css --watch --style expanded --source-map",
    "build:uncompressed": "sass styles.scss lightrope.css --style expanded"
  },
  "devDependencies": {
    "sass": "^1.69.0"
  }
}
```

Then run:
```bash
# For production (compressed)
npm run build

# For development (watch mode)
npm run dev
```

## SCSS Development Workflow

### 1. Variables (colors, sizes)
Edit `_variables.scss` to change colors, dimensions, and other design tokens:
```scss
$light-cyan: rgba(0, 255, 255, 1);
$globe-width: 12px;
```

### 2. Mixins (reusable code)
Add common patterns to `_mixins.scss`:
```scss
@mixin light-animation($duration: 2s) {
  animation-duration: $duration;
  animation-fill-mode: both;
}
```

### 3. Components
Create new component files in `components/`:
- `_lightrope.scss` - Main component
- `_other-component.scss` - Additional components (future)

### 4. Theme Overrides
Add theme-specific styles to `_theme-overrides.scss`:
```scss
.theme-custom {
  .lightrope {
    z-index: 999;
  }
}
```

### 5. Main Entry Point
`styles.scss` imports everything:
```scss
@import 'variables';
@import 'mixins';
@import 'components/lightrope';
@import 'theme-overrides';
```

## Drupal Integration

### How Drupal Loads the Styles
1. Module loads `css/lightrope.css` in `custom_newyear_init()`
2. Drupal caches and aggregates CSS
3. Final CSS is served to the browser

### Development vs Production
- **Development**: Use uncompressed CSS with source maps
- **Production**: Always use compressed CSS (`npm run build`)

## Best Practices

### SCSS Structure
- Keep variables at the top level
- Use BEM-style naming for complex components
- Group related properties together
- Use meaningful variable names

### Performance
- Compile to production CSS before deployment
- Drupal will aggregate and minify the final CSS
- Keep SCSS files organized for maintainability

### Browser Compatibility
- Use SCSS features that compile to widely supported CSS
- Test compiled CSS in target browsers
- Consider autoprefixer if needed

## Troubleshooting

### Compilation Errors
```bash
# Check for syntax errors
sass --check styles.scss

# Verbose output for debugging
sass styles.scss lightrope.css --trace
```

### Module Not Loading Styles
1. Ensure `css/lightrope.css` exists and is compiled
2. Check Drupal cache is cleared after CSS changes
3. Verify path in `drupal_add_css()` is correct

### SCSS Not Compiling
1. Check Sass installation: `sass --version`
2. Verify file paths in import statements
3. Check for circular imports

## Future Enhancements

### Automated Build Pipeline
- Add git hooks to auto-compile on commit
- Integrate with CI/CD for production builds
- Add CSS prefixing for better browser support

### Additional Features
- CSS custom properties for runtime theming
- Build process for JavaScript files
- Automated testing for CSS output