<?php
/**
 * Simple test to verify module structure
 */

// Check if all required files exist
$module_files = array(
  'custom_newyear.info',
  'custom_newyear.module', 
  'custom_newyear.admin.inc',
  'README.md'
);

echo "Testing Custom New Year Module Structure:\n";
echo "=========================================\n\n";

foreach ($module_files as $file) {
  if (file_exists($file)) {
    echo "✓ $file exists\n";
    $size = filesize($file);
    echo "  Size: $size bytes\n";
  } else {
    echo "✗ $file missing\n";
  }
}

echo "\nModule testing complete.\n";