#[no_mangle]
pub extern "C" fn mul(x: i32) -> i32 {
    x * 2
}

struct ProjectBuilderCommand {
    raw_cmd: std::process::Command,
}

impl ProjectBuilderCommand {
    fn new(project_name: &str) -> ProjectBuilderCommand {
        let mut raw_cmd = std::process::Command::new(Self::get_default_tool_name());
        raw_cmd.args(Self::get_default_tool_args());
        raw_cmd.arg(project_name);
        raw_cmd.current_dir(ProjectBuilder::get_default_project_directories_location());

        ProjectBuilderCommand { raw_cmd: raw_cmd }
    }

    fn execute(&mut self) {
        self.raw_cmd
            .status()
            .expect("Cannot execute command to create new game project");
    }

    fn get_default_tool_name() -> &'static str {
        "cargo"
    }

    fn get_default_tool_args() -> &'static [&'static str] {
        &["new", "--bin"]
    }
}

struct ProjectBuilder {
    default_project_directory: String,
}

impl ProjectBuilder {
    fn get_default_project_directories_location() -> &'static str {
        "/tmp/no_engines"
    }

    fn make_directory() {
        std::fs::create_dir(Self::get_default_project_directories_location());
        Self::fill_project_with_default_files();
    }

    fn fill_project_with_default_files() {
        let mut cmd = ProjectBuilderCommand::new("not_uncharted_12");
        cmd.execute();
    }
}

#[no_mangle]
pub extern "C" fn create_new_project(p_project_name: *const std::os::raw::c_char) {
    let c_project_name = unsafe { std::ffi::CStr::from_ptr(p_project_name) };
    let final_name = c_project_name.to_str().expect("cannot convert to str");
    ProjectBuilder::make_directory();
}
