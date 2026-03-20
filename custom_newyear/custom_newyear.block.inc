<?php
/**
 * @file
 * Block implementation for Custom New Year lightrope
 */

/**
 * Implements hook_block_info().
 */
function custom_newyear_block_info() {
  $blocks['lightrope_block'] = array(
    'info' => t('Christmas Lightrope'),
    'cache' => DRUPAL_CACHE_GLOBAL,
    'status' => 0,
    'region' => -1, // User must place in a region
  );
  
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function custom_newyear_block_view($delta = '') {
  $block = array();
  
  if ($delta == 'lightrope_block') {
    $enabled = variable_get('custom_newyear_enabled', 0);
    
    if ($enabled) {
      $html = _custom_newyear_get_lightrope_html();
      
      // Get styling settings
      $background_color = variable_get('custom_newyear_background_color', '');
      $margin_top = variable_get('custom_newyear_margin_top', -15);
      $margin_bottom = variable_get('custom_newyear_margin_bottom', 0);
      $custom_css = variable_get('custom_newyear_custom_css', '');
      
      // Build inline styles
      $inline_styles = '';
      if ($background_color) {
        $inline_styles .= "background-color: $background_color; ";
      }
      if ($margin_top !== '') {
        $inline_styles .= "margin-top: {$margin_top}px; ";
      }
      if ($margin_bottom !== '') {
        $inline_styles .= "margin-bottom: {$margin_bottom}px; ";
      }
      
      // Wrap content in styled container
      $styled_html = '<div class="lightrope-container" style="' . $inline_styles . '">';
      if ($custom_css) {
        $styled_html .= '<style>' . $custom_css . '</style>';
      }
      $styled_html .= $html . '</div>';
      
      $block['subject'] = t('Christmas Lightrope');
      $block['content'] = array(
        '#markup' => $styled_html,
        '#weight' => 0,
      );
    }
  }
  
  return $block;
}

/**
 * Helper function to get available theme regions.
 */
function custom_newyear_get_theme_regions() {
  global $theme_key;
  
  $regions = array();
  
  // Get active theme
  if ($theme_key) {
    $theme_info = list_themes();
    if (isset($theme_info[$theme_key])) {
      $theme_data = $theme_info[$theme_key];
      
      // Get regions from theme info
      if (isset($theme_data->info['regions'])) {
        $regions = array_keys($theme_data->info['regions']);
      }
    }
  }
  
  // If no regions found, provide common ones
  if (empty($regions)) {
    $regions = array(
      'header',
      'navigation',
      'sidebar_first',
      'sidebar_second',
      'content',
      'footer',
      'page_top',
      'page_bottom',
    );
  }
  
  // Sort and format for form options
  $region_options = array();
  foreach ($regions as $region) {
    // Create human-readable label
    $label = ucfirst(str_replace('_', ' ', $region));
    $region_options[$region] = t($label);
  }
  
  return $region_options;
}