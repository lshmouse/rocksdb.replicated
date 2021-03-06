// apps
# include "rrdb.app.example.h"
# include "rrdb.server.impl.h"

// tools
# include <dsn/tool/simulator.h>
# include <dsn/tool/nativerun.h>
# include <dsn/toollet/tracer.h>
# include <dsn/toollet/profiler.h>
# include <dsn/toollet/fault_injector.h>

int main(int argc, char** argv)
{
	// register replication application provider
    dsn::replication::register_replica_provider<::dsn::apps::rrdb_service_impl>("rrdb");

    // register all possible services
    dsn::service::system::register_service<::dsn::replication::meta_service_app>("meta");
    dsn::service::system::register_service<::dsn::replication::replication_service_app>("replica");
	dsn::service::system::register_service<::dsn::apps::rrdb_client_app>("client");

	// register all possible tools and toollets
	dsn::tools::register_tool<dsn::tools::nativerun>("nativerun");
	dsn::tools::register_tool<dsn::tools::simulator>("simulator");
	dsn::tools::register_toollet<dsn::tools::tracer>("tracer");
	dsn::tools::register_toollet<dsn::tools::profiler>("profiler");
	dsn::tools::register_toollet<dsn::tools::fault_injector>("fault_injector");

	// specify what services and tools will run in config file, then run
	dsn::service::system::run("config.ini", true);
	return 0;
}
