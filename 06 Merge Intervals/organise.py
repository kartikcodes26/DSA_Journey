
from pathlib import Path
import shutil

# Your existing Merge Intervals directory
ROOT = Path(r"D:\01_DSA\DSA_Journey\06 Merge Intervals")

# Pattern -> files belonging to that pattern
PATTERNS = {
    "01_Sorting_and_Merging": [
        "01_merge_intervals.cpp",
    ],

    "02_Interval_Insertion_and_Coverage": [
        "02_insert_and_merge_intervals.cpp",
        "08_Remove_Covered_Intervals.cpp",
    ],

    "03_Greedy_Interval_Scheduling": [
        "06_N_Meetings_in_one_room.cpp",
        "07_Non_Overlapping_Intervals.cpp",
        "09_Minimum_Number_Of_Arrows.cpp",
    ],

    "04_Interval_Intersection_and_Free_Time": [
        "04_Find_Intersection.cpp",
        "10_Common_Free_Time.cpp",
    ],

    "05_Scheduling_and_Resources": [
        "03_meeting_rooms.cpp",
        "05_meeting_rooms_ii.cpp",
        "13_Minimum_Platforms.cpp",
    ],

    "06_Advanced_Interval_Data_Structures": [
        "11_My_Calender.cpp",
        "12_My_Calendar_II.cpp",
        # Future problem: Data Stream as Disjoint Intervals (LC 352)
    ],

    "07_Binary_Search_Heaps_and_DP": [
        "14_Minimum_Interval_to_Include_Each_Query.cpp",
        # Future: Maximum Profit in Job Scheduling (LC 1235)
    ],

    "08_Advanced_Room_Scheduling": [
        # Future: Meeting Rooms III (LC 2402)
    ],
}


def organize():
    if not ROOT.is_dir():
        print(f"Directory not found: {ROOT}")
        return

    moved = 0
    missing = 0

    for pattern, filenames in PATTERNS.items():
        target_dir = ROOT / pattern

        # Create the pattern folder, even if it is empty
        target_dir.mkdir(parents=True, exist_ok=True)

        for filename in filenames:
            # Search the root directory for the existing file
            source = ROOT / filename
            destination = target_dir / filename

            if not source.is_file():
                # Already organized or missing
                if destination.is_file():
                    print(f"Already organized: {filename}")
                else:
                    print(f"Not found: {filename}")
                    missing += 1
                continue

            # Never overwrite an existing file
            if destination.exists():
                print(f"SKIPPED (destination exists): {filename}")
                continue

            shutil.move(str(source), str(destination))
            print(f"Moved: {filename} -> {pattern}/")
            moved += 1

    print("\nOrganization complete!")
    print(f"Files moved: {moved}")
    print(f"Files missing: {missing}")
    print(f"Root directory: {ROOT}")


if __name__ == "__main__":
    organize()
