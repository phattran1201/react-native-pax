# react_native_pax_pods.rb
# Fixes symbol conflicts between SSZipArchive and libPOSLinkAdmin.a.
# Both export the same unz*/zip* symbols as globals; the fix prefixes
# SSZipArchive's copies so the linker sees distinct names.
#
# Usage — add to your app's Podfile:
#
#   require_relative '../node_modules/@haroldtran/react-native-pax/react_native_pax_pods'
#
# Then call inside your post_install block:
#
#   post_install do |installer|
#     react_native_pax_pods(installer)
#     # ... other post_install steps
#   end

PAX_SSZ_SYMBOLS = %w[
  unzClose unzCloseCurrentFile unzGetCurrentFileInfo unzGetFilePos
  unzGetGlobalComment unzGetGlobalInfo unzGetLocalExtrafield unzGetOffset
  unzGoToFilePos unzGoToFirstFile unzGoToNextFile unzLocateFile
  unzOpen unzOpen2 unzOpenCurrentFile unzOpenCurrentFile2 unzOpenCurrentFile3
  unzOpenCurrentFilePassword unzReadCurrentFile unzRepair unzSetOffset
  unzStringFileNameCompare unzeof unztell
  zipClose zipCloseFileInZip zipCloseFileInZipRaw zipOpen zipOpen2
  zipOpenNewFileInZip zipOpenNewFileInZip2 zipOpenNewFileInZip3 zipWriteInFileInZip
].freeze

def react_native_pax_pods(installer)
  installer.pods_project.targets.each do |target|
    next unless target.name == 'SSZipArchive'

    target.build_configurations.each do |config|
      # Normalize to Array — value may be a String in some Xcode configurations,
      # and String#<< would concatenate in-place instead of appending a new entry.
      defs = config.build_settings['GCC_PREPROCESSOR_DEFINITIONS'] || ['$(inherited)']
      defs = defs.is_a?(String) ? defs.split : defs.dup

      PAX_SSZ_SYMBOLS.each do |sym|
        entry = "#{sym}=ssz_#{sym}"
        defs << entry unless defs.include?(entry)
      end

      config.build_settings['GCC_PREPROCESSOR_DEFINITIONS'] = defs
    end
  end
end
