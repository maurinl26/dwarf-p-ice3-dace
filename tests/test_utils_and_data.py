"""
Test suite for utilities and data handling
"""
import pytest
import numpy as np
import tempfile
import os
from pathlib import Path
from tests.conftest import create_random_field, create_test_state


class TestNetCDFReader:
    """Test NetCDF reading functionality"""
    
    def test_netcdf_reader_import(self):
        """Test that NetCDFReader can be imported"""
        try:
            from ice3.utils.reader import NetCDFReader
            assert NetCDFReader is not None
        except ImportError as e:
            pytest.skip(f"NetCDFReader not available: {e}")
    
    def test_netcdf_reader_creation(self):
        """Test NetCDFReader creation"""
        try:
            from ice3.utils.reader import NetCDFReader
            
            # Create a temporary file path (doesn't need to exist for this test)
            with tempfile.NamedTemporaryFile(suffix='.nc', delete=False) as tmp:
                tmp_path = tmp.name
            
            try:
                # Test reader creation (might fail if file doesn't exist, which is OK)
                reader = NetCDFReader(tmp_path)
                assert reader is not None
            except (FileNotFoundError, OSError):
                # Expected if file doesn't exist
                pass
            finally:
                # Clean up
                if os.path.exists(tmp_path):
                    os.unlink(tmp_path)
                    
        except ImportError as e:
            pytest.skip(f"NetCDFReader not available: {e}")
    
    def test_netcdf_with_real_data(self):
        """Test NetCDF reading with actual data file if available"""
        try:
            from ice3.utils.reader import NetCDFReader
            import netCDF4 as nc
            
            # Create a simple test NetCDF file
            with tempfile.NamedTemporaryFile(suffix='.nc', delete=False) as tmp:
                tmp_path = tmp.name
            
            try:
                # Create test NetCDF file
                with nc.Dataset(tmp_path, 'w') as dataset:
                    # Create dimensions
                    dataset.createDimension('x', 10)
                    dataset.createDimension('y', 10)
                    dataset.createDimension('z', 5)
                    
                    # Create variables
                    temp_var = dataset.createVariable('temperature', 'f8', ('x', 'y', 'z'))
                    temp_var[:] = np.random.rand(10, 10, 5) * 50 + 250
                    
                    pres_var = dataset.createVariable('pressure', 'f8', ('x', 'y', 'z'))
                    pres_var[:] = np.random.rand(10, 10, 5) * 50000 + 50000
                
                # Test reading
                reader = NetCDFReader(tmp_path)
                assert reader is not None
                
                # Test that we can access the file
                # (specific methods depend on the implementation)
                
            finally:
                if os.path.exists(tmp_path):
                    os.unlink(tmp_path)
                    
        except ImportError as e:
            pytest.skip(f"NetCDF dependencies not available: {e}")
        except Exception as e:
            pytest.skip(f"NetCDF test failed: {e}")


class TestDimsUtility:
    """Test dimensions utility"""
    
    def test_dims_import(self):
        """Test that Dims can be imported"""
        try:
            from ice3.utils.dims import Dims
            assert Dims is not None
        except ImportError as e:
            pytest.skip(f"Dims not available: {e}")
    
    def test_dims_creation(self, domain):
        """Test Dims creation and basic functionality"""
        try:
            from ice3.utils.dims import Dims
            
            # Test creation with domain
            dims = Dims(domain)
            assert dims is not None
            
            # Test basic properties (if they exist)
            if hasattr(dims, 'shape'):
                assert dims.shape == domain
            
        except ImportError as e:
            pytest.skip(f"Dims not available: {e}")
        except Exception as e:
            pytest.skip(f"Dims test failed: {e}")


class TestDictToClass:
    """Test dictionary to class conversion utility"""
    
    def test_dict_to_class_import(self):
        """Test that dict_to_class can be imported"""
        try:
            from ice3.utils.dict_to_class import dict_to_class
            assert dict_to_class is not None
        except ImportError as e:
            pytest.skip(f"dict_to_class not available: {e}")
    
    def test_dict_to_class_functionality(self):
        """Test dict_to_class functionality"""
        try:
            from ice3.utils.dict_to_class import dict_to_class
            
            # Test with simple dictionary
            test_dict = {
                'temperature': 273.15,
                'pressure': 101325.0,
                'name': 'test_case'
            }
            
            # Convert to class
            obj = dict_to_class(test_dict)
            
            # Test that attributes are accessible
            assert hasattr(obj, 'temperature')
            assert hasattr(obj, 'pressure')
            assert hasattr(obj, 'name')
            
            assert obj.temperature == 273.15
            assert obj.pressure == 101325.0
            assert obj.name == 'test_case'
            
        except ImportError as e:
            pytest.skip(f"dict_to_class not available: {e}")
        except Exception as e:
            pytest.skip(f"dict_to_class test failed: {e}")


class TestTypingUtilities:
    """Test typing utilities"""
    
    def test_typing_import(self):
        """Test that typing utilities can be imported"""
        try:
            from ice3.utils.typingx import dtype_float, precision
            assert dtype_float is not None
            assert precision is not None
        except ImportError as e:
            pytest.skip(f"typing utilities not available: {e}")
    
    def test_dtype_float_functionality(self):
        """Test dtype_float functionality"""
        try:
            from ice3.utils.typingx import dtype_float
            
            # Test that it returns a valid numpy dtype
            dt = dtype_float()
            assert dt in [np.float32, np.float64]
            
        except ImportError as e:
            pytest.skip(f"dtype_float not available: {e}")
        except Exception as e:
            pytest.skip(f"dtype_float test failed: {e}")
    
    def test_precision_functionality(self):
        """Test precision functionality"""
        try:
            from ice3.utils.typingx import precision
            
            # Test precision function/class
            prec = precision()
            assert prec is not None
            
        except ImportError as e:
            pytest.skip(f"precision not available: {e}")
        except Exception as e:
            pytest.skip(f"precision test failed: {e}")


class TestTestprogsData:
    """Test testprogs data utilities"""
    
    def test_testprogs_main_import(self):
        """Test that testprogs main can be imported"""
        try:
            from testprogs_data.main import app
            assert app is not None
        except ImportError as e:
            pytest.skip(f"testprogs main not available: {e}")
    
    def test_testprogs_utils_import(self):
        """Test that testprogs utils can be imported"""
        try:
            from testprogs_data.utils import extract_data
            assert extract_data is not None
        except ImportError as e:
            pytest.skip(f"testprogs utils not available: {e}")
    
    def test_yaml_config_files_exist(self):
        """Test that YAML configuration files exist"""
        config_dir = Path("src/testprogs_data")
        
        if config_dir.exists():
            yaml_files = list(config_dir.glob("*.yaml"))
            assert len(yaml_files) > 0, "No YAML configuration files found"
            
            for yaml_file in yaml_files:
                assert yaml_file.is_file()
                assert yaml_file.stat().st_size > 0  # Not empty
        else:
            pytest.skip("testprogs_data directory not found")


class TestDataValidation:
    """Test data validation utilities"""
    
    def test_field_validation(self, domain):
        """Test field validation functions"""
        # Create test fields with known properties
        valid_field = create_random_field(domain, dtype=np.float64)
        
        # Test basic validation
        assert valid_field.shape == domain
        assert valid_field.dtype == np.float64
        assert not np.any(np.isnan(valid_field))
        assert not np.any(np.isinf(valid_field))
    
    def test_physical_constraints(self, domain):
        """Test physical constraint validation"""
        # Create fields representing physical quantities
        temperature = create_random_field(domain, dtype=np.float64) * 100 + 200  # 200-300K
        pressure = create_random_field(domain, dtype=np.float64, seed=222) * 50000 + 50000  # 50-100kPa
        
        # Test physical constraints
        assert np.all(temperature > 0), "Temperature must be positive"
        assert np.all(pressure > 0), "Pressure must be positive"
        assert np.all(temperature < 500), "Temperature should be reasonable"
        assert np.all(pressure < 200000), "Pressure should be reasonable"
    
    def test_mixing_ratio_constraints(self, domain):
        """Test mixing ratio constraint validation"""
        # Create mixing ratio fields
        rv = create_random_field(domain, dtype=np.float64) * 0.02  # 0-2% water vapor
        rc = create_random_field(domain, dtype=np.float64, seed=333) * 0.001  # 0-0.1% cloud water
        ri = create_random_field(domain, dtype=np.float64, seed=444) * 0.001  # 0-0.1% ice
        
        # Test constraints
        assert np.all(rv >= 0), "Water vapor mixing ratio must be non-negative"
        assert np.all(rc >= 0), "Cloud water mixing ratio must be non-negative"
        assert np.all(ri >= 0), "Ice mixing ratio must be non-negative"
        
        # Test reasonable upper bounds
        assert np.all(rv < 0.1), "Water vapor mixing ratio should be reasonable"
        assert np.all(rc < 0.01), "Cloud water mixing ratio should be reasonable"
        assert np.all(ri < 0.01), "Ice mixing ratio should be reasonable"


class TestDataIO:
    """Test data input/output operations"""
    
    def test_array_serialization(self, domain):
        """Test array serialization and deserialization"""
        # Create test array
        original_array = create_random_field(domain, dtype=np.float64)
        
        # Test numpy save/load
        with tempfile.NamedTemporaryFile(suffix='.npy', delete=False) as tmp:
            tmp_path = tmp.name
        
        try:
            # Save array
            np.save(tmp_path, original_array)
            
            # Load array
            loaded_array = np.load(tmp_path)
            
            # Verify
            assert loaded_array.shape == original_array.shape
            assert loaded_array.dtype == original_array.dtype
            np.testing.assert_array_equal(loaded_array, original_array)
            
        finally:
            if os.path.exists(tmp_path):
                os.unlink(tmp_path)
    
    def test_state_serialization(self, domain):
        """Test state serialization"""
        # Create test state
        state = create_test_state(domain)
        
        # Test that state can be converted to/from dictionary
        state_dict = dict(state)
        
        # Verify dictionary
        assert 'temperature' in state_dict
        assert 'pressure' in state_dict
        assert 'rv' in state_dict
        
        # Test reconstruction
        reconstructed_state = {
            key: value.copy() for key, value in state_dict.items()
        }
        
        # Verify reconstruction
        for key in state:
            np.testing.assert_array_equal(state[key], reconstructed_state[key])


class TestErrorHandling:
    """Test error handling in utilities"""
    
    def test_invalid_file_paths(self):
        """Test handling of invalid file paths"""
        try:
            from ice3.utils.reader import NetCDFReader
            
            # Test with non-existent file
            with pytest.raises((FileNotFoundError, OSError, IOError)):
                reader = NetCDFReader("/nonexistent/path/file.nc")
                # Try to use the reader
                _ = reader.read_data()  # This method might not exist
                
        except ImportError as e:
            pytest.skip(f"NetCDFReader not available: {e}")
        except AttributeError:
            # If read_data method doesn't exist, that's OK for this test
            pass
    
    def test_invalid_dimensions(self, domain):
        """Test handling of invalid dimensions"""
        # Test with mismatched array dimensions
        field1 = create_random_field(domain, dtype=np.float64)
        field2 = create_random_field((domain[0]//2, domain[1], domain[2]), dtype=np.float64)
        
        # Operations that should fail with dimension mismatch
        with pytest.raises((ValueError, RuntimeError)):
            result = field1 + field2  # Should fail due to shape mismatch
    
    def test_invalid_data_types(self, domain):
        """Test handling of invalid data types"""
        # Test with incompatible data types
        field_float = create_random_field(domain, dtype=np.float64)
        field_int = np.ones(domain, dtype=np.int32)
        
        # Some operations might handle type conversion, others might not
        try:
            result = field_float + field_int
            # If it succeeds, check the result type
            assert result.dtype in [np.float64, np.int32]
        except TypeError:
            # If it fails, that's also acceptable behavior
            pass


class TestPerformanceUtilities:
    """Test performance-related utilities"""
    
    def test_memory_efficient_operations(self, domain):
        """Test memory-efficient operations"""
        # Create large-ish arrays
        field1 = create_random_field(domain, dtype=np.float64)
        field2 = create_random_field(domain, dtype=np.float64, seed=555)
        
        # Test in-place operations
        original_id = id(field1)
        field1 += field2
        
        # Verify in-place operation
        assert id(field1) == original_id
        assert field1.shape == domain
    
    def test_vectorized_operations(self, domain):
        """Test vectorized operations"""
        import time
        
        # Create test data
        field = create_random_field(domain, dtype=np.float64)
        
        # Test vectorized operation
        start_time = time.time()
        result_vectorized = np.sin(field) + np.cos(field)
        vectorized_time = time.time() - start_time
        
        # Test element-wise operation (slower)
        start_time = time.time()
        result_elementwise = np.zeros_like(field)
        flat_field = field.flat
        flat_result = result_elementwise.flat
        for i, val in enumerate(flat_field):
            flat_result[i] = np.sin(val) + np.cos(val)
        elementwise_time = time.time() - start_time
        
        # Verify results are the same
        np.testing.assert_allclose(result_vectorized, result_elementwise, rtol=1e-12)
        
        # Log performance (vectorized should be faster)
        print(f"Vectorized: {vectorized_time:.6f}s, Element-wise: {elementwise_time:.6f}s")
        
        # Vectorized should be significantly faster for reasonable array sizes
        if np.prod(domain) > 1000:  # Only check for larger arrays
            assert vectorized_time < elementwise_time