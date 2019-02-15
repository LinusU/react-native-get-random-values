Pod::Spec.new do |s|
  s.name         = "react-native-get-random-values"
  s.version      = "1.1.0"
  s.summary      = "A small implementation of `getRandomValues` for React Native"
  s.homepage     = "https://github.com/LinusU/react-native-get-random-values"
  s.license      = "MIT"
  s.author       = { "Linus Unnebäck" => "linus@folkdatorn.se" }
  s.source       = { :git => "https://github.com/LinusU/react-native-get-random-values.git", :tag => "v#{s.version}" }
  s.source_files = "ios/RNGetRandomValues.{h,m}"
  s.platform     = :ios, '8.0'
  s.dependency 'React'
end
