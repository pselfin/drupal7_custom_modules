<?php
/**
 * @file
 * Admin form for Custom New Year module
 */

/**
 * Admin configuration form.
 */
function custom_newyear_admin_form($form, &$form_state) {
  $form['custom_newyear_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Christmas Lightrope'),
    '#description' => t('Check this to enable the animated Christmas lightrope decoration.'),
    '#default_value' => variable_get('custom_newyear_enabled', 0),
  );
  
  $form['custom_newyear_snow_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Snow Effect'),
    '#description' => t('Check this to enable falling snow animation on your website.'),
    '#default_value' => variable_get('custom_newyear_snow_enabled', 0),
  );
  
  $form['snow_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Snow Effect Settings'),
    '#description' => t('Configure the falling snow animation.'),
    '#states' => array(
      'visible' => array(
        ':input[name="custom_newyear_snow_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['snow_settings']['custom_newyear_snow_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Snowflakes'),
    '#description' => t('Maximum number of snowflakes to display (recommended: 20-100).'),
    '#default_value' => variable_get('custom_newyear_snow_count', 50),
    '#size' => 5,
    '#maxlength' => 3,
  );
  
  $form['snow_settings']['custom_newyear_snow_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum Snowflake Size'),
    '#description' => t('Maximum size of snowflakes in pixels (recommended: 20-60).'),
    '#default_value' => variable_get('custom_newyear_snow_size', 40),
    '#size' => 5,
    '#maxlength' => 2,
  );
  
  $form['snow_settings']['custom_newyear_snow_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Falling Speed'),
    '#description' => t('Falling speed of snowflakes (recommended: 0.3-2.0).'),
    '#default_value' => variable_get('custom_newyear_snow_speed', 0.7),
    '#size' => 5,
    '#maxlength' => 3,
  );
  
  $form['snow_settings']['custom_newyear_snow_color_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary Snow Color'),
    '#description' => t('Main color for snowflakes (e.g., #fff, #f0f8ff). Default: white (#fff).'),
    '#default_value' => variable_get('custom_newyear_snow_color_1', '#fff'),
    '#size' => 10,
    '#maxlength' => 20,
  );
  
  $form['snow_settings']['custom_newyear_snow_color_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Secondary Snow Color'),
    '#description' => t('Additional color for snowflakes (optional). Leave empty to use single color.'),
    '#default_value' => variable_get('custom_newyear_snow_color_2', ''),
    '#size' => 10,
    '#maxlength' => 20,
  );
  
  $form['snow_settings']['custom_newyear_snow_color_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Tertiary Snow Color'),
    '#description' => t('Additional color for snowflakes (optional). Leave empty to use fewer colors.'),
    '#default_value' => variable_get('custom_newyear_snow_color_3', ''),
    '#size' => 10,
    '#maxlength' => 20,
  );
  
  $form['snow_settings']['color_preview'] = array(
    '#type' => 'item',
    '#title' => t('Color Preview'),
    '#markup' => _custom_newyear_get_snow_color_preview(),
    '#description' => t('Preview of snowflake colors based on your settings.'),
    '#weight' => 15,
  );
  
  $form['lightrope_styling'] = array(
    '#type' => 'fieldset',
    '#title' => t('Lightrope Styling'),
    '#description' => t('Customize the appearance and positioning of the lightrope.'),
    '#states' => array(
      'visible' => array(
        ':input[name="custom_newyear_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['lightrope_styling']['custom_newyear_background_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background Color'),
    '#description' => t('CSS color for the container background (e.g., #000, rgba(0,0,0,0.8), transparent). Leave empty for no background.'),
    '#default_value' => variable_get('custom_newyear_background_color', ''),
    '#size' => 15,
    '#maxlength' => 50,
  );
  
  $form['lightrope_styling']['custom_newyear_margin_top'] = array(
    '#type' => 'textfield',
    '#title' => t('Top Margin (px)'),
    '#description' => t('Space above the lightrope in pixels. Use negative values to move up. Default: -15.'),
    '#default_value' => variable_get('custom_newyear_margin_top', -15),
    '#size' => 5,
    '#maxlength' => 10,
  );
  
  $form['lightrope_styling']['custom_newyear_margin_bottom'] = array(
    '#type' => 'textfield',
    '#title' => t('Bottom Margin (px)'),
    '#description' => t('Space below the lightrope in pixels.'),
    '#default_value' => variable_get('custom_newyear_margin_bottom', 0),
    '#size' => 5,
    '#maxlength' => 10,
  );
  
  $form['lightrope_styling']['custom_newyear_custom_css'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom CSS'),
    '#description' => t('Additional CSS rules for the lightrope container. For example: <code>box-shadow: 0 2px 5px rgba(0,0,0,0.3); padding: 10px;</code>'),
    '#default_value' => variable_get('custom_newyear_custom_css', ''),
    '#rows' => 3,
    '#maxlength' => 500,
  );
  
  $form['block_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Placement'),
    '#description' => t('Instructions for placing the Christmas lightrope block.'),
    '#states' => array(
      'visible' => array(
        ':input[name="custom_newyear_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $theme_regions = custom_newyear_get_theme_regions();
  
  $form['block_info']['placement_instructions'] = array(
    '#type' => 'item',
    '#title' => t('How to place the lightrope:'),
    '#markup' => '
      <ol>
        <li>' . t('Enable the lightrope above') . '</li>
        <li>' . t('Go to <a href="@blocks-url">Structure > Blocks</a>', array('@blocks-url' => url('admin/structure/block'))) . '</li>
        <li>' . t('Find "Christmas Lightrope" block in the disabled section') . '</li>
        <li>' . t('Drag it to your desired region:') . '<br><strong>' . implode(', ', $theme_regions) . '</strong></li>
        <li>' . t('Save the configuration') . '</li>
      </ol>
      <p><strong>' . t('Recommended regions:') . '</strong> ' . t('Header, Page top, or Above content area for best visual effect.') . '</p>',
  );
  
  $form['preview'] = array(
    '#type' => 'fieldset',
    '#title' => t('Preview'),
    '#description' => t('Preview of effects (when enabled).'),
    '#states' => array(
      'visible' => array(
        'or' => array(
          ':input[name="custom_newyear_enabled"]' => array('checked' => TRUE),
          ':input[name="custom_newyear_snow_enabled"]' => array('checked' => TRUE),
        ),
      ),
    ),
  );
  
  $form['preview']['snow_preview'] = array(
    '#markup' => _custom_newyear_get_snow_preview(),
    '#weight' => 6,
    '#states' => array(
      'visible' => array(
        ':input[name="custom_newyear_snow_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['preview']['block_note'] = array(
    '#type' => 'item',
    '#title' => t('Lightrope Block'),
    '#markup' => '<p>' . t('The Christmas lightrope will appear as a Drupal block that you can place in any region of your theme.') . '</p>',
    '#weight' => 5,
    '#states' => array(
      'visible' => array(
        ':input[name="custom_newyear_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['#submit'][] = 'custom_newyear_admin_form_submit';
  
  return system_settings_form($form);
}

/**
 * Submit handler for admin form.
 */
function custom_newyear_admin_form_submit($form, &$form_state) {
  // Clear any cached CSS/JS when settings change
  drupal_clear_css_cache();
  drupal_clear_js_cache();
  
  // Optionally add a message about clearing cache
  drupal_set_message(t('Custom New Year settings have been saved. Cache has been cleared.'), 'status');
}

/**
 * Helper function to generate snow effect preview HTML.
 */
function _custom_newyear_get_snow_preview() {
  // Add minimal CSS for snow preview
  $css = '
    .snow-preview {
      position: relative;
      height: 100px;
      background: linear-gradient(to bottom, #1a1a2e, #16213e);
      border: 1px solid #444;
      overflow: hidden;
      margin: 10px 0;
    }
    .snow-preview .snowflake {
      position: absolute;
      color: white;
      font-size: 12px;
      animation: snowfall 3s linear infinite;
    }
    .snowflake:nth-child(1) { left: 10%; animation-delay: 0s; }
    .snowflake:nth-child(2) { left: 30%; animation-delay: 0.5s; }
    .snowflake:nth-child(3) { left: 50%; animation-delay: 1s; }
    .snowflake:nth-child(4) { left: 70%; animation-delay: 1.5s; }
    .snowflake:nth-child(5) { left: 90%; animation-delay: 2s; }
    
    @keyframes snowfall {
      0% { top: -20px; opacity: 0; }
      10% { opacity: 1; }
      90% { opacity: 1; }
      100% { top: 120px; opacity: 0; }
    }
  ';
  drupal_add_css($css, array('type' => 'inline', 'group' => CSS_THEME, 'weight' => 100));
  
  $html = '<div class="snow-preview">';
  $html .= '<p>' . t('The snow effect will look like this when enabled:') . '</p>';
  
  // Add snowflakes for preview
  for ($i = 1; $i <= 5; $i++) {
    $html .= '<div class="snowflake">*</div>';
  }
  
  $html .= '</div>';
  
  return $html;
}

/**
 * Helper function to generate snow color preview.
 */
function _custom_newyear_get_snow_color_preview() {
  $color1 = variable_get('custom_newyear_snow_color_1', '#fff');
  $color2 = variable_get('custom_newyear_snow_color_2', '');
  $color3 = variable_get('custom_newyear_snow_color_3', '');
  
  $colors = array_filter(array($color1, $color2, $color3));
  
  if (empty($colors)) {
    $colors = array('#fff');
  }
  
  $css = '
    .snow-color-preview {
      display: flex;
      gap: 10px;
      margin: 10px 0;
      padding: 10px;
      border: 1px solid #ccc;
      background: #f9f9f9;
    }
    .snow-color-preview .color-item {
      width: 30px;
      height: 30px;
      border-radius: 50%;
      border: 2px solid #333;
    }
  ';
  
  drupal_add_css($css, array('type' => 'inline', 'group' => CSS_THEME, 'weight' => 100));
  
  $html = '<div class="snow-color-preview">';
  foreach ($colors as $color) {
    $html .= '<div class="color-item" style="background-color: ' . check_plain($color) . ';" title="' . check_plain($color) . '"></div>';
  }
  $html .= '</div>';
  
  if (count($colors) == 1) {
    $html .= '<p><em>' . t('Single color: @color', array('@color' => $color1)) . '</em></p>';
  } else {
    $html .= '<p><em>' . t('Colors will be randomly applied to snowflakes') . '</em></p>';
  }
  
  return $html;
}