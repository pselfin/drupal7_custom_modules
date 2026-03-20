# Custom New Year Module for Drupal 7

## Description
The Custom New Year module adds an animated Christmas lightrope decoration to your Drupal 7 website. The module includes a flexible admin interface that allows you to enable/disable the decoration and choose where to place it on your site.

## Features
- Animated Christmas lightrope with colorful blinking lights
- Falling snow effect with customizable parameters
- Drupal Block system for flexible placement
- Auto-detection of theme regions
- Advanced styling options (background color, margins, custom CSS)
- Admin configuration form with preview for snow effect
- Responsive design that works across different screen sizes
- SCSS-based development with organized component structure
- JavaScript integration for snow animation
- Performance optimized with external CSS and JS files
- Modular CSS architecture for easy customization
- Compiled CSS for optimal Drupal performance

## Installation

1. Copy the `custom_newyear` folder to your Drupal 7 installation's `/sites/all/modules/custom/` directory
2. Enable the module through Drupal's admin interface:
   - Go to `Admin > Modules`
   - Find "Custom New Year" in the list
   - Check the box to enable it
3. Configure the module:
   - Go to `Admin > Configuration > User Interface > Custom New Year Settings`
   - Enable the lightrope by checking "Enable Christmas Lightrope"
   - Enable the snow effect by checking "Enable Snow Effect"
   - Customize snow effect settings (number, size, speed)
   - Configure lightrope styling (background color, margins, custom CSS)
   - Go to `Admin > Structure > Blocks` to place the "Christmas Lightrope" block
   - Drag the block to your desired region (automatically detects theme regions)
   - Save the block configuration

## Configuration

### Admin Settings
Navigate to `Admin > Configuration > User Interface > Custom New Year Settings` to access the configuration options:

#### Main Settings
- **Enable Christmas Lightrope**: Master checkbox to turn the lightrope decoration on/off
- **Enable Snow Effect**: Checkbox to enable falling snow animation

#### Snow Effect Settings
Configure snow effect parameters:
- **Number of Snowflakes**: Maximum snowflakes to display (20-100 recommended)
- **Maximum Snowflake Size**: Size of snowflakes in pixels (20-60 recommended)
- **Falling Speed**: How fast snowflakes fall (0.3-2.0 recommended)
- **Primary Snow Color**: Main color for snowflakes (e.g., #fff, #f0f8ff)
- **Secondary Snow Color**: Additional color for snowflakes (optional)
- **Tertiary Snow Color**: Third color for snowflakes (optional)
- **Color Preview**: Visual preview of selected colors

#### Lightrope Styling
Customize the appearance and positioning:
- **Background Color**: CSS color for container background (e.g., #000, rgba(0,0,0,0.8), transparent)
- **Top Margin (px)**: Space above the lightrope in pixels (use negative values to move up)
- **Bottom Margin (px)**: Space below the lightrope in pixels
- **Custom CSS**: Additional CSS rules for the lightrope container

#### Block Placement
The lightrope is now displayed as a Drupal block for maximum flexibility:

1. Enable the lightrope above
2. Go to `Admin > Structure > Blocks`
3. Find "Christmas Lightrope" block in the disabled section
4. Drag it to your desired region (theme regions are automatically detected)
5. Save the configuration

**Recommended regions**: Header, Page top, or Above content area for best visual effect.

### Container Selection Tips
- **Body**: Recommended for most cases, gives the best visual effect spanning the full page width
- **Header**: Good for sites where the lightrope should be part of the header design
- **Page Top**: Similar to body but can work better with some themes
- **Custom regions**: If your theme has custom regions, you can specify them by editing the code

## Usage

### Lightrope Block Placement
The Christmas lightrope is now implemented as a Drupal block for maximum flexibility:

1. **Enable the lightrope** in the module settings
2. **Configure styling** (background color, margins, custom CSS)
3. **Go to Blocks page**: `Admin > Structure > Blocks`
4. **Place the block**: Find "Christmas Lightrope" in the disabled section
5. **Drag to region**: Place it in any available theme region (automatically detected)
6. **Save configuration**: The block will now appear on your site

### Snow Effect
The snow effect works automatically when enabled:
- Appears on all pages site-wide
- No manual placement required
- Can be configured independently from the lightrope

### Features

#### Lightrope Features:
- 40 animated light bulbs in different colors (cyan, green, magenta)
- Randomized blinking patterns for a natural effect
- Smooth animations using CSS keyframes
- Responsive design that adapts to different screen sizes
- Flexible placement via Drupal Block system
- Advanced styling options (background, margins, custom CSS)
- Auto-detection of theme regions
- Compatible with any Drupal 7 theme

#### Snow Effect Features:
- Customizable number of snowflakes (20-100 recommended)
- Adjustable snowflake size and falling speed
- Customizable snowflake colors (up to 3 different colors)
- Color preview in admin interface
- Smooth falling animation with varying speeds
- Responsive design that works on all screen sizes
- Cross-browser compatible JavaScript animation
- Site-wide automatic display
- Dynamic JavaScript generation based on admin settings

## Technical Details

### SCSS Development
The module uses SCSS for organized CSS development:

1. **Source Files**: Located in `css/` directory:
   - `styles.scss` - Main entry point
   - `_variables.scss` - Design tokens and variables
   - `_mixins.scss` - Reusable SCSS mixins
   - `components/_lightrope.scss` - Main component styles

2. **Compilation Process**:
   - Install Sass: `npm install -g sass`
   - Compile: `sass css/styles.scss css/lightrope.css --style compressed`
   - Watch for changes: `sass css/styles.scss css/lightrope.css --watch`

3. **Drupal Integration**:
   - Module loads compiled `css/lightrope.css`
   - Drupal handles CSS aggregation and caching

For detailed SCSS development workflow, see `SCSS_BUILD_PROCESS.md`.

### Hooks Used
- `hook_menu()`: Creates the admin configuration page
- `hook_permission()`: Defines admin permissions
- `hook_init()`: Loads CSS when the module is enabled
- `hook_page_alter()`: Injects the lightrope HTML into the page

### Files Structure
```
custom_newyear/
├── custom_newyear.info      # Module information file
├── custom_newyear.module    # Main module file
├── custom_newyear.admin.inc # Admin configuration form
├── custom_newyear.block.inc # Block implementation for lightrope
├── css/                     # SCSS source files
│   ├── styles.scss         # Main SCSS entry point
│   ├── _variables.scss     # SCSS variables
│   ├── _mixins.scss        # SCSS mixins
│   ├── components/
│   │   └── _lightrope.scss # Lightrope component styles
│   ├── _theme-overrides.scss # Theme-specific styles
│   ├── lightrope.css       # Compiled CSS (used by Drupal)
│   └── package.json        # Build configuration
├── js/                      # JavaScript files
│   └── snow-fall.js        # Snow effect animation script
├── SCSS_BUILD_PROCESS.md    # SCSS development documentation
└── README.md               # This documentation
```

### CSS Animation
The module uses CSS animations with keyframes to create the blinking effect:
- Three different animation patterns (flash-1, flash-2, flash-3)
- Different timing and duration for each pattern
- Opacity changes to simulate lights turning on/off

## Customization

### SCSS Development (Recommended)
For easier customization, use the SCSS source files:

1. **Modify Variables**: Edit `css/_variables.scss` to change colors and dimensions:
   ```scss
   $light-cyan: rgba(0, 255, 255, 1);  // Change cyan color
   $globe-width: 12px;                  // Change light bulb width
   ```

2. **Customize Styles**: Edit `css/components/_lightrope.scss` for advanced changes

3. **Build Process**: After changes, compile SCSS:
   ```bash
   cd css
   sass styles.scss lightrope.css --style compressed
   ```

### Manual CSS Editing (Legacy)
To modify styles directly in compiled CSS:
- Edit `css/lightrope.css`
- Look for RGB values and animation properties
- Adjust colors and positioning as needed

### Adjusting Positioning
To customize where the lightrope appears:
1. Modify the CSS margin values in the `.lightrope` class
2. Adjust the z-index if needed to ensure proper layering
3. Consider changing the container selection in the admin settings

### Adding More Animation Variations
Extend the CSS/SCSS animations by:
1. Adding more nth-child selectors with different timing
2. Creating additional @keyframes with unique patterns
3. Adjusting animation-duration values for more variety
4. Using SCSS variables for easier management

### Snow Effect Color Configuration
The snow effect supports customizable colors through the admin interface:

#### Snow Color Settings:
- **Primary Snow Color**: Main color for snowflakes (default: #ffffff)
- **Secondary Snow Color**: Additional color for variety (optional)
- **Tertiary Snow Color**: Third color option (optional)

#### Color Format Examples:
- **Hex colors**: `#ffffff`, `#ff0000`, `#f0f8ff`
- **RGB colors**: `rgb(255, 255, 255)`, `rgba(255, 0, 0, 0.8)`
- **Color names**: `white`, `lightblue`, `silver`

#### Popular Color Schemes:
- **Classic Winter**: `#ffffff` (white)
- **Light Blue Winter**: `#f0f8ff` (Alice Blue)
- **Silver Snow**: `#c0c0c0` (silver)
- **Multi-colored**: `#ffffff`, `#f0f8ff`, `#c0c0c0`
- **Warm Winter**: `#fff8dc`, `#ffebcd`, `#f5f5dc`
- **Cool Blue**: `#e6f3ff`, `#cce7ff`, `#b3d9ff`
- **Themed Pink**: `#ffc0cb`, `#ffe4e1`, `#fff0f5`
- **Golden Snow**: `#ffd700`, `#ffffe0`, `#fffacd`

#### Tips:
- Leave secondary/tertiary fields empty to use fewer colors
- Colors are randomly assigned to snowflakes for natural variation
- Use contrasting colors for better visibility against different backgrounds
- Test color combinations with the admin preview before saving

## Troubleshooting

### Lightrope Not Appearing
1. Check that the module is enabled in Admin > Modules
2. Verify the "Enable Christmas Lightrope" checkbox is checked
3. Clear Drupal's cache after making changes
4. Check browser developer tools for CSS/JS errors

### Layout Issues
1. Ensure the selected container exists in your theme
2. Check for CSS conflicts with your theme's styles
3. Adjust the z-index value if the lightrope appears behind other elements

### Performance
- The CSS is loaded from external file for optimal performance and browser caching
- No external JavaScript dependencies
- Minimal DOM overhead with simple HTML structure
- Proper Drupal CSS aggregation and optimization support

## Compatibility
- Drupal 7.x
- Works with most Drupal 7 themes
- Compatible with most modern browsers supporting CSS3 animations

## License
This module is provided as-is for educational and development purposes.

## Support
For issues or questions about this module:
1. Check the troubleshooting section above
2. Review your theme's compatibility
3. Test with a default Drupal theme to isolate issues

## Changelog
### Version 7.x-1.0
- Initial release
- Admin configuration interface
- Multiple container placement options
- CSS-based animations
- Responsive design support