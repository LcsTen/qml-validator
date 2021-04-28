#include <iostream>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QCoreApplication>

std::ostream& operator<<(std::ostream& os, const QString s){
	return os << s.toStdString();
}

int main(int argc, char** argv){
	if(argc < 2){
		std::cout << "Usage: qml-validator <qmlfile>" << std::endl;
		return 1;
	}
	
	QCoreApplication app(argc, argv);
	QQmlEngine engine;
	QQmlComponent component(&engine);
	QObject::connect(&component, &QQmlComponent::statusChanged,
			 [&component, argv](QQmlComponent::Status status){
		if(status == QQmlComponent::Status::Null){
			std::cout << "Component is Null." << std::endl;
		}else if(status == QQmlComponent::Status::Ready){
			// OK!
		}else if(status == QQmlComponent::Status::Loading){
			std::cout << "Component is Loading." << std::endl;
		}else if(status == QQmlComponent::Status::Error){
			std::cout << "Errors happened while loading " << argv[1]
				  << ": " << std::endl;
			for(QQmlError error : component.errors()){
				std::cout << error.toString() << std::endl;
			}
			exit(1);
		}
	});
	component.loadUrl(QUrl(argv[1]));
}
