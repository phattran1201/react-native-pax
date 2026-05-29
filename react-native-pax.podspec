require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-pax"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]
  s.source       = { :git => "https://github.com/phattran1201/react-native-pax.git", :tag => "#{s.version}" }

  s.platforms    = { :ios => "12.0" }
  s.source_files = "ios/**/*.{h,m,mm}"
  s.frameworks   = "ExternalAccessory", "CoreBluetooth", "UIKit", "Foundation"

  s.vendored_libraries = [
    'ios/POSLinkSemiIntegrationSDK/libPOSLinkSemiIntegration.a',
    'ios/POSLinkAdminSDK/libPOSLinkAdmin.a'
  ]
  s.preserve_paths = [
    'ios/POSLinkSemiIntegrationSDK/Header/**',
    'ios/POSLinkAdminSDK/Header/**'
  ]

  s.pod_target_xcconfig = {
    'HEADER_SEARCH_PATHS' => '$(inherited) "$(PODS_TARGET_SRCROOT)/ios/POSLinkSemiIntegrationSDK/Header" "$(PODS_TARGET_SRCROOT)/ios/POSLinkAdminSDK/Header"',
    'OTHER_LDFLAGS' => '-ObjC',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

  install_modules_dependencies(s)
end
